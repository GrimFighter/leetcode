class Solution
{
    public:
        string fractionAddition(string expression)
        {
            stringstream ss(expression);

            int a, b;
            int A = 0, B = 1;
            char i;

            while (ss >> a >> i >> b)
            {
                A = A *b + B * a;
                B = B * b;

                int div = abs(gcd(A, B));

                A /= div;
                B /= div;
            }

            return to_string(A) + "/" + to_string(B);
        }
};