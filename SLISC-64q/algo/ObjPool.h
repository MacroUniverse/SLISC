template <class T>
class ObjPool {
private:
    vector<unique_ptr<T>> pool;

public:
	ObjPool(Long_I n) { alloc(n); }
	ObjPool(cons ObjPool &) = delete;
	ObjPool(ObjPool &&rhs) : pool(move(rhs.pool)) {};
	ObjPool &operator=(cons ObjPool &) = delete;
	ObjPool &operator=(ObjPool &&rhs) { pool = move(rhs.pool); };

	Long size() const { return (Long)pool.size(); }

	void alloc(Long n) {
		pool.reserve((size_t)n);
		while (n--)
            pool.emplace_back(make_unique<T>());
	}

    unique_ptr<T> get() {
        if (pool.empty()) {
            return make_unique<T>();
        }
		else {
            unique_ptr<T> obj = move(pool.back());
            pool.pop_back();
            return obj;
        }
    }

    void put(unique_ptr<T> &obj) {
        pool.push_back(move(obj));
    }
};
