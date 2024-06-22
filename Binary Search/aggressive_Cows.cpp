 sort(stalls.begin(), stalls.end()); // Sort stall positions
        
        int s = 1; // Minimum possible distance
        int e = stalls[n-1] - stalls[0]; // Maximum possible distance
        int ans = 0;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            
            if (isPossible(stalls, k, n, mid)) {
                ans = mid;
                s = mid + 1; // Try for a larger distance
            } else {
                e = mid - 1; // Try for a smaller distance
            }
        }
        
        return ans;
