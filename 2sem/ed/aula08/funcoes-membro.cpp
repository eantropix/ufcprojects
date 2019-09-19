template <typename X, typename Y>
struct Par
{
    X x; Y y;
    X primeiro() {return x;}
    Y segundo() {return y;}
};

int main()
{
    Par<double, char> p;
    p.x = 3.14; p.y = '!';
    double qq_coisa = p.primeiro() - p.segundo();
}