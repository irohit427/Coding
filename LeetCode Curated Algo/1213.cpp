vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    map<int, int> hmap;
    for (int i = 0; i < arr1.size(); i++) {
        hmap[arr1[i]]++;
        hmap[arr2[i]]++;
        hmap[arr3[i]]++;
    }         
    vector<int> result;
    for (auto m: hmap) {
        if (m.second == 3)
            result.push_back(m.first);
    } 
    return result;
}

vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    vector<int> result;

    for (int i = 0, j = 0, k = 0; i < arr1.size() and j < arr2.size() and k < arr3.size();) {
        if (arr1[i] == arr2[j] and arr2[j] == arr3[k]) {
            result.push_back(arr1[i]);
            i++; j++; k++;
        } else {
            int min_ele = min({arr1[i], arr2[j], arr3[k]});
            if (arr1[i] == min_ele) i++;
            if (arr2[j] == min_ele) j++;
            if (arr3[k] == min_ele) k++;
        }
    }
    return result;
}