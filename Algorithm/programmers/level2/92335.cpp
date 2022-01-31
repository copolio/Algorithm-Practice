#include <string>
#include <vector>

using namespace std;

string toString(int n, int k) {
    string result = "";
    if (k == 10) return to_string(n);
    while(n > 0) {
        int digit = n % k;
        n /= k;
        result = to_string(digit) + result;
    }
    return result;
}

bool isPrime(long n) {
    if (n <= 1) return false;
    for (long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string num = toString(n, k);
    int pos = 0;
    while(pos < num.size()) {
        int next = num.find_first_of('0', pos);
        if (next == string::npos) {
            string part = num.substr(pos);
            if (isPrime(stol(part))) {
                answer++;
            }
            break;
        } else {
            string part = num.substr(pos, next - pos);
            pos = next;
            while(pos < num.size()) {
                if (num[pos] != '0') break;
                pos++;
            }
            if (isPrime(stol(part))) {
                answer++;
            }
        }
        
    }
    
    return answer;
}