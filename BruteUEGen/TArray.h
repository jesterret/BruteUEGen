#pragma once
template<class T, size_t N = 1> class TArray
{
public:
    T* Data[N];
    DWORD ArrayNum;

    TArray() : Data(nullptr), ArrayNum(0){};
    DWORD Num()
    {
        return ArrayNum;
    };
    T& operator()(int i)
    {
        return Data[i];
    };
    const T& operator()(int i) const
    {
        return Data[i];
    };
};
class FString : public TArray<wchar_t>
{

};