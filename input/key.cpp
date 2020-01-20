// Modified from Thor Library

#include "key.h"

class Exception : public std::runtime_error
{
public:
    explicit Exception(const std::string &message)
        : std::runtime_error(message)
    {
    }
};

class StringConversionException : public Exception
{
public:
    explicit StringConversionException(const std::string &message)
        : Exception(message)
    {
    }
};

class KeyEventMap
{
public:
    KeyEventMap()
    {
        init();
    }

    void init()
    {
        #define INSERT_MAPPING(identifier) umap.insert(std::make_pair(sf::Keyboard::identifier, #identifier))

        INSERT_MAPPING(Unknown);
        INSERT_MAPPING(A);
        INSERT_MAPPING(B);
        INSERT_MAPPING(C);
        INSERT_MAPPING(D);
        INSERT_MAPPING(E);
        INSERT_MAPPING(F);
        INSERT_MAPPING(G);
        INSERT_MAPPING(H);
        INSERT_MAPPING(I);
        INSERT_MAPPING(J);
        INSERT_MAPPING(K);
        INSERT_MAPPING(L);
        INSERT_MAPPING(M);
        INSERT_MAPPING(N);
        INSERT_MAPPING(O);
        INSERT_MAPPING(P);
        INSERT_MAPPING(Q);
        INSERT_MAPPING(R);
        INSERT_MAPPING(S);
        INSERT_MAPPING(T);
        INSERT_MAPPING(U);
        INSERT_MAPPING(V);
        INSERT_MAPPING(W);
        INSERT_MAPPING(X);
        INSERT_MAPPING(Y);
        INSERT_MAPPING(Z);
        INSERT_MAPPING(Num0);
        INSERT_MAPPING(Num1);
        INSERT_MAPPING(Num2);
        INSERT_MAPPING(Num3);
        INSERT_MAPPING(Num4);
        INSERT_MAPPING(Num5);
        INSERT_MAPPING(Num6);
        INSERT_MAPPING(Num7);
        INSERT_MAPPING(Num8);
        INSERT_MAPPING(Num9);
        INSERT_MAPPING(Escape);
        INSERT_MAPPING(LControl);
        INSERT_MAPPING(LShift);
        INSERT_MAPPING(LAlt);
        INSERT_MAPPING(LSystem);
        INSERT_MAPPING(RControl);
        INSERT_MAPPING(RShift);
        INSERT_MAPPING(RAlt);
        INSERT_MAPPING(RSystem);
        INSERT_MAPPING(Menu);
        INSERT_MAPPING(LBracket);
        INSERT_MAPPING(RBracket);
        INSERT_MAPPING(SemiColon);
        INSERT_MAPPING(Comma);
        INSERT_MAPPING(Period);
        INSERT_MAPPING(Quote);
        INSERT_MAPPING(Slash);
        INSERT_MAPPING(BackSlash);
        INSERT_MAPPING(Tilde);
        INSERT_MAPPING(Equal);
        INSERT_MAPPING(Dash);
        INSERT_MAPPING(Space);
        INSERT_MAPPING(Return);
        INSERT_MAPPING(BackSpace);
        INSERT_MAPPING(Tab);
        INSERT_MAPPING(PageUp);
        INSERT_MAPPING(PageDown);
        INSERT_MAPPING(End);
        INSERT_MAPPING(Home);
        INSERT_MAPPING(Insert);
        INSERT_MAPPING(Delete);
        INSERT_MAPPING(Add);
        INSERT_MAPPING(Subtract);
        INSERT_MAPPING(Multiply);
        INSERT_MAPPING(Divide);
        INSERT_MAPPING(Left);
        INSERT_MAPPING(Right);
        INSERT_MAPPING(Up);
        INSERT_MAPPING(Down);
        INSERT_MAPPING(Numpad0);
        INSERT_MAPPING(Numpad1);
        INSERT_MAPPING(Numpad2);
        INSERT_MAPPING(Numpad3);
        INSERT_MAPPING(Numpad4);
        INSERT_MAPPING(Numpad5);
        INSERT_MAPPING(Numpad6);
        INSERT_MAPPING(Numpad7);
        INSERT_MAPPING(Numpad8);
        INSERT_MAPPING(Numpad9);
        INSERT_MAPPING(F1);
        INSERT_MAPPING(F2);
        INSERT_MAPPING(F3);
        INSERT_MAPPING(F4);
        INSERT_MAPPING(F5);
        INSERT_MAPPING(F6);
        INSERT_MAPPING(F7);
        INSERT_MAPPING(F8);
        INSERT_MAPPING(F9);
        INSERT_MAPPING(F10);
        INSERT_MAPPING(F11);
        INSERT_MAPPING(F12);
        INSERT_MAPPING(F13);
        INSERT_MAPPING(F14);
        INSERT_MAPPING(F15);
        INSERT_MAPPING(Pause);

        static_assert(sf::Keyboard::KeyCount == 101, "Number of SFML keys has changed");
        #undef INSERT_MAPPING
    }

    std::string mapInstance(sf::Keyboard::Key key)
    {
        if(umap.count(key))
            return umap[key];
        else
            throw StringConversionException("No match string found");
    }
private:
    std::unordered_map<int, std::string> umap;
};

std::string toString(sf::Keyboard::Key key)
{
    static KeyEventMap k;
    return k.mapInstance(key);
}
