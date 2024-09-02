class RecentCounter {
public:
    RecentCounter() {
        
    }
    queue<int> q;

    int ping(int t) {
        q.push(t);
        int lower = t-3000;
        int upper = t;

        while(!q.empty() && (q.front() < lower || q.front() >upper)){
            q.pop();
        }

        return q.size();
    }
};
