class Ratio
{
public:
	friend Ratio operator*(Ratio r1, Ratio r2);
	friend Ratio operator/(Ratio r1, Ratio r2);
	friend Ratio operator+(Ratio r1, Ratio r2);
	friend Ratio operator-(Ratio r1, Ratio r2);
	friend bool operator==(Ratio r1, Ratio r2);
	friend bool operator>=(Ratio r1, Ratio r2);
	void operator*=(const Ratio& r)	//سربار گزاری عملگر جایگزین
	{
		num = num * r.num;
		den = den * r.den;
	}
	void operator/=(const Ratio& r)	//سربار گزاری عملگر جایگزین
	{
		num = num * r.den;
		den = den * r.num;
	}
	void operator+=(const Ratio& r)	//سربار گزاری عملگر جایگزین
	{
		num = (num * r.den) + (r.num*den);
		den = den * r.den;
	}
	void operator-=(const Ratio& r)	//سربار گزاری عملگر جایگزین
	{
		num = (num * r.den) - (r.num*den);
		den = den * r.den;
	}
	void operator++()	//Prefix
	{
		num = num + den;
	}
	void operator--()	//Prefix
	{
		num = num - den;
	}
	void operator++(int)	//postfix
	{
		num = num + den;
	}
	void operator--(int)	//Postfix
	{
		num = num - den;
	}
	void operator=(const Ratio& r)	//عملگر جایگزین
	{
		num = r.num;
		den = r.den;
	}
	Ratio(int n = 0, int d = 0) :num(n), den(d) {}	//سازنده پیشفرض
	Ratio(const Ratio& r) :num(r.num), den(r.den) {}	//سازنده کپی
	void print() { cout << num << '/' << den << endl; }	//چاپ
private:
	int num, den;	//عضو خصوصی
};

Ratio operator*(Ratio r1, Ratio r2)	//سربار گزاری عملگر حسابی
{
	Ratio z(r1.num*r2.num, r1.den*r2.den);
	return z;
}
Ratio operator/(Ratio r1, Ratio r2)	//سربار گزاری عملگر حسابی
{
	Ratio z(r1.num*r2.den, r1.den*r2.num);
	return z;
}
Ratio operator+(Ratio r1, Ratio r2)	//سربار گزاری عملگر حسابی
{
	Ratio z((r1.num*r2.den) + (r1.den*r2.num), (r1.den)*(r2.den));
	return z;
}
Ratio operator-(Ratio r1, Ratio r2)	//سربار گزاری عملگر حسابی
{
	Ratio z((r1.num*r2.den) - (r1.den*r2.num), (r1.den)*(r2.den));
	return z;
}
bool operator==(Ratio r1, Ratio r2)	//سربار گزاری عملگر رابطه ای
{
	return (r1.num*r2.den == r1.den*r2.num);
}
bool operator>=(Ratio r1, Ratio r2)	//سربار گزاری عملگر رابطه ای
{
	return (r1.num*r2.den >= r1.den*r2.num);
}