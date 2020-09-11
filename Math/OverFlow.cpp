bool ofMul(int a, int b) {
        if (b== 0) return 0;
        int n= a* b;
        if (a!= n/ b) return 1;
        return 0;
}

bool ofadd(int x, int a) {
        if ((x> 0) && (a> INT_MAX- x)) return 1;
        else return 0;
}
