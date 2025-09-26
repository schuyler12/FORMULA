#include <bits/stdc++.h>
using namespace std;
struct Student {
    string name;
    int marks;
};

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<Student> v;
    v.reserve(n);
    for (int i=0;i<n;i++) {
        Student s; cin >> s.name >> s.marks;
        v.push_back(s);
    }
    // sort descending by marks; if tie, lexicographically by name
    sort(v.begin(), v.end(), [](const Student& a, const Student& b){
        if (a.marks != b.marks) return a.marks > b.marks;
        return a.name < b.name;
    });
    int upto = min(n, 3);
    for (int i=0;i<upto;i++) {
        cout << v[i].name << ' ' << v[i].marks << '\n';
    }
    return 0;
}
