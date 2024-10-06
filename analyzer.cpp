#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "StringData (2).h"

using namespace std;

int linear_search(const vector<string>& container, const string& element) {
    for (int i=0; i < container.size(); i++) {
        if (container[i]==element)
            return i;
    }
    return -1;
}

int binary_search(const vector<string>& container, const string& element) {
    int low=0, high=container.size()-1;
    while (low<=high) {
        int mid = (low + high)/2;
        if (container[mid]==element)
            return mid;
        else if (container[mid]>element)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int main() {
    vector<string> data = getStringData();
    auto beg = std::chrono::system_clock::now();
    int index = linear_search(data,"not_here");
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> sec= end-beg;
    cout << "Index found by Linear Search for not_here: " << index << endl;
    cout << "Linear Search Time for not_here: " << sec.count() << " seconds." << endl;
    beg= std::chrono::system_clock::now();  // Start timer
    index = binary_search(data, "not_here");
    end = std::chrono::system_clock::now();
    sec = end - beg;
    cout << "Index found by Binary Search for not_here: " << index << endl;
    cout << "Binary Search Time for not_here: " << sec.count() << " seconds." << endl;
    cout << endl;

    beg = std::chrono::system_clock::now();
    index = linear_search(data,"mzzzz");
    end = std::chrono::system_clock::now();
    sec= end-beg;
    cout << "Index found by Linear Search for mzzzz: " << index << endl;
    cout << "Linear Search Time for mzzzz: " << sec.count() << " seconds." << endl;
    beg= std::chrono::system_clock::now();  // Start timer
    index = binary_search(data, "mzzzz");
    end = std::chrono::system_clock::now();
    sec = end - beg;
    cout << "Index found by Binary Search for mzzzz: " << index << endl;
    cout << "Binary Search Time for mzzzz: " << sec.count() << " seconds." << endl;
    cout << endl;

    beg = std::chrono::system_clock::now();
    index = linear_search(data,"aaaaa");
    end = std::chrono::system_clock::now();
    sec= end-beg;
    cout << "Index found by Linear Search for aaaaa: " << index << endl;
    cout << "Linear Search Time for aaaaa: " << sec.count() << " seconds." << endl;
    beg= std::chrono::system_clock::now();  // Start timer
    index = binary_search(data, "aaaaa");
    end = std::chrono::system_clock::now();
    sec = end - beg;
    cout << "Index found by Binary Search for aaaaa: " << index << endl;
    cout << "Binary Search Time for aaaaa: " << sec.count() << " seconds." << endl;




    return 0;
}
