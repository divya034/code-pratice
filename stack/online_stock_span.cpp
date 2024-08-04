class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        while(!s.empty() && s.top().second <= price){
            span += s.top().first;
            s.pop();
        }

        s.push({span, price});    
        return span; 
    }

};

above we'll be getting rid of numbers in between:
class StockSpanner {
public:
    vector<pair<int,int>> arr;
    StockSpanner() {
        vector<int> arr;
    }

    int next(int price) {
        int span = 1;

        if(arr.size() == 0){
        arr.push_back({span,price});
        return span;
        }

        for(int i = arr.size() - 1; i>=0; i--){
            if(arr[i].second <= price){
                span += arr[i].first;
                arr.pop_back();
            }
            else{
                break;
            }
        }

        arr.push_back({span,price});

        return span;

    }
};



MY more time complexity solution: where we traverse ALL the elemnets in the array
we dont need to

class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        vector<int> arr;
    }

    int next(int price) {

        arr.push_back(price);
        int n = arr.size();

        int span = 1;

        for(int i = n-2; i>=0; i--){
            if(arr[i] <= price){
                span++;
            }
            else{
                break;
            }
        }

        return span;

    }

};
