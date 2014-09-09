#include <cstdio>

//*****************************************************************************
//
// FizzBuzzPrinter
//
//*****************************************************************************

//=============================================================================
template <bool THREE, bool FIVE, unsigned N>
struct FizzBuzzPrinter
{
    static void Print ()
    {
        printf("%u\n", N);
    }
};

//=============================================================================
template <unsigned N>
struct FizzBuzzPrinter<true, false, N>
{
    static void Print ()
    {
        printf("Fizz\n", N);
    }
};

//=============================================================================
template <unsigned N>
struct FizzBuzzPrinter<false, true, N>
{
    static void Print ()
    {
        printf("Buzz\n", N);
    }
};

//=============================================================================
template <unsigned N>
struct FizzBuzzPrinter<true, true, N>
{
    static void Print ()
    {
        printf("FizzBuzz\n", N);
    }
};



//*****************************************************************************
//
// FizzBuzz
//
//*****************************************************************************

//=============================================================================
template <unsigned N>
struct FizzBuzz
{
    static void Exec ()
    {
        FizzBuzz<N - 1>::Exec();
        FizzBuzzPrinter<N % 3 == 0, N % 5 == 0, N>::Print();
    }
};

//=============================================================================
template <>
struct FizzBuzz<0>
{
    static void Exec ()
    {
        // Do nothing, base case
    }
};


//=============================================================================
void main ()
{
    FizzBuzz<100>::Exec();
}