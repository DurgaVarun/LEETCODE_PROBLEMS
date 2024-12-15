class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& cls, int extra) {
        auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };

        // Max-heap to store classes by their gain in decreasing order
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& c : cls) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        // Distribute extra students
        while (extra--) {
            auto [g, pt] = pq.top();
            pq.pop();
            int p = pt.first, t = pt.second;
            pq.push({gain(p + 1, t + 1), {p + 1, t + 1}});
        }

        // Compute the final average pass ratio
        double sum = 0;
        while (!pq.empty()) {
            auto [g, pt] = pq.top();
            pq.pop();
            sum += (double)pt.first / pt.second;
        }

        return sum / cls.size();
    }
};