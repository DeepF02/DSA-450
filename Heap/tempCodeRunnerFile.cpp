or<int>ans;
        deque<int>dq;
        for(int i=0; i<k; i++){
            while(!dq.empty() && dq.back()<arr[i])dq.pop_back();
            dq.push_back(arr[i]);
        }
        ans.push_back(dq.front());
        if(dq.front()==arr[0])dq.pop_front();
        for(int i=k; i<n; i++){
            while(!dq.empty() && dq.back()<arr[i])dq.pop_back();
            dq.push_back(arr[i]);
            ans.push_back(dq.front());
            if(dq.front()==arr[i-k+1])dq.pop_front();
        }