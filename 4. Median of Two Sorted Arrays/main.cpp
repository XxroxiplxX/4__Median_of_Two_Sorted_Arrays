#include <iostream>
#include "vector"
using namespace std;
double mean(int a, int b) {
    return (double) (a + b)/2;
}
void print(int A[], int p, int q) {
    for (int i = p; i < q; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
double get_median(int C[], int p, int q) {
    int n = q - p;
    if (n%2 == 1) {
        return C[n/2 + p];
    } else {
        return mean(C[n/2 + p], C[n/2 - 1 + p]);
    }
}
double median(int A[], int B[], int p1, int q1, int p2, int q2) {
    cout << p1 << " " << q1 << " " << p2 << " " << q2 << endl;
    std::cout << "A: ";
    print(A,p1,q1);
    std::cout << "B: ";
    print(B,p2,q2);

    if (q1 - p1 == 1 and q2 - p2 == 1) {
        return mean(A[p1], B[p2]);
    }
    if (q1 - p1 == 0 or q2 - p2 == 0) {
        return 0;
    }
    double m1 = get_median(A,p1, q1);
    double m2 = get_median(B,p2, q2);
    std::cout << m1 << " ; " << m2 << std::endl;
    if (m1 < m2) {
        std::cout << "P + L" << std::endl;
        std::cout << std::endl;
        //P + L
        return median(A,B, mean(p1,q1), q1, p2, mean(p2,q2));
    } else {
        std::cout << "L + P" << std::endl;
        std::cout << std::endl;
        //L + P
        return median(A,B,p1, mean(p1,q1), mean(p2,q2), q2);
    }
}

int main() {
    int A[] = {1,3,7,10,12, 20};
    int B[] = {0,7,11,15};

    std::cout << median(A,B,0,6,0,4) << std::endl;
    //cout << get_median(A,2,4);
    return 0;
}
