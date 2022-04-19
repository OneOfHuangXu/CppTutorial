template<typename T>
class complex
{
public:
	complex( T r = 0, T i = 0) : re(r), im(i) {}

	T real() const { return re; }
	T imag() const { return im; }
	
	complex& operator += (const complex&);
private:
	T re, im;
};