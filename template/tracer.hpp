#include <iostream>

class SortTracer {
private:
	int value;
	int generation;
	static long n_created;
	static long n_destroyed;
	static long n_assigned;
	static long n_compared;
	static long n_max_live;

	static void update_max_live() {
		if (n_created-n_destroyed > n_max_live) {
			n_max_live = n_created - n_destroyed;
		}
	}

public:
	int val() {
		return value;
	}
	static long creations() {
		return n_created;
	}
	static long destructions() {
		return n_destroyed;
	}
	static long assignments() {
		return n_assigned;
	}
	static long comparisons() {
		return n_compared;
	}
	static long max_live() {
		return n_max_live;
	}

public:
	SortTracer (int v = 0) : value(v), generation(1) {
		++n_created;
		update_max_live();
		std::cerr << "SortTracer #" << n_created
			<< ", created generation " << generation
			<< " (total: " << n_created - n_destroyed
			<< ")\n";
	}

	SortTracer (SortTracer const& b)
		: value(b.value), generation(b.generation + 1) {
			++n_created;
			update_max_live();
			std::cerr << "SortTracer #" << n_created
				<< ", copied as generation " << generation
				<< " (total: " << n_created - n_destroyed
				<< ")\n";
	}

	~SortTracer() {
		++n_destroyed;
		update_max_live();
		std::cerr << "SortTracer generation " << generation
			<< " destroyed (total: "
			<< n_created - n_destroyed << ")\n";
	}

	SortTracer& operator= (SortTracer const& b) {
		++n_assigned;
		std::cerr << "SortTracer assignment #" << n_assigned
			<< " (generation " << generation
			<< " = " << b.generation
			<< ")\n";
		value = b.value;
		return *this;
	}

	friend bool operator < (SortTracer const& a, SortTracer const& b) {
		++n_compared;
		std::cerr << "SortTracer comparison #" << n_compared
			<< " (generation " << a.generation
			<< " < " << b.generation
			<< ")\n";
		return a.value < b.value;
	}
};