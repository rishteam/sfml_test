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

class EventMap
{
protected:
    std::unordered_map<int, std::string> umap;
};

#define INSERT_MAPPING(class, identifier) EventMap::umap.insert(std::make_pair(sf:: class :: identifier, #identifier))

class KeyEventMap : public EventMap
{
public:
    KeyEventMap()
    {
#define KB_MAP(identifier) INSERT_MAPPING(Keyboard, identifier)

        KB_MAP(Unknown);
        KB_MAP(A);
        KB_MAP(B);
        KB_MAP(C);
        KB_MAP(D);
        KB_MAP(E);
        KB_MAP(F);
        KB_MAP(G);
        KB_MAP(H);
        KB_MAP(I);
        KB_MAP(J);
        KB_MAP(K);
        KB_MAP(L);
        KB_MAP(M);
        KB_MAP(N);
        KB_MAP(O);
        KB_MAP(P);
        KB_MAP(Q);
        KB_MAP(R);
        KB_MAP(S);
        KB_MAP(T);
        KB_MAP(U);
        KB_MAP(V);
        KB_MAP(W);
        KB_MAP(X);
        KB_MAP(Y);
        KB_MAP(Z);
        KB_MAP(Num0);
        KB_MAP(Num1);
        KB_MAP(Num2);
        KB_MAP(Num3);
        KB_MAP(Num4);
        KB_MAP(Num5);
        KB_MAP(Num6);
        KB_MAP(Num7);
        KB_MAP(Num8);
        KB_MAP(Num9);
        KB_MAP(Escape);
        KB_MAP(LControl);
        KB_MAP(LShift);
        KB_MAP(LAlt);
        KB_MAP(LSystem);
        KB_MAP(RControl);
        KB_MAP(RShift);
        KB_MAP(RAlt);
        KB_MAP(RSystem);
        KB_MAP(Menu);
        KB_MAP(LBracket);
        KB_MAP(RBracket);
        KB_MAP(SemiColon);
        KB_MAP(Comma);
        KB_MAP(Period);
        KB_MAP(Quote);
        KB_MAP(Slash);
        KB_MAP(BackSlash);
        KB_MAP(Tilde);
        KB_MAP(Equal);
        KB_MAP(Dash);
        KB_MAP(Space);
        KB_MAP(Return);
        KB_MAP(BackSpace);
        KB_MAP(Tab);
        KB_MAP(PageUp);
        KB_MAP(PageDown);
        KB_MAP(End);
        KB_MAP(Home);
        KB_MAP(Insert);
        KB_MAP(Delete);
        KB_MAP(Add);
        KB_MAP(Subtract);
        KB_MAP(Multiply);
        KB_MAP(Divide);
        KB_MAP(Left);
        KB_MAP(Right);
        KB_MAP(Up);
        KB_MAP(Down);
        KB_MAP(Numpad0);
        KB_MAP(Numpad1);
        KB_MAP(Numpad2);
        KB_MAP(Numpad3);
        KB_MAP(Numpad4);
        KB_MAP(Numpad5);
        KB_MAP(Numpad6);
        KB_MAP(Numpad7);
        KB_MAP(Numpad8);
        KB_MAP(Numpad9);
        KB_MAP(F1);
        KB_MAP(F2);
        KB_MAP(F3);
        KB_MAP(F4);
        KB_MAP(F5);
        KB_MAP(F6);
        KB_MAP(F7);
        KB_MAP(F8);
        KB_MAP(F9);
        KB_MAP(F10);
        KB_MAP(F11);
        KB_MAP(F12);
        KB_MAP(F13);
        KB_MAP(F14);
        KB_MAP(F15);
        KB_MAP(Pause);

        static_assert(sf::Keyboard::KeyCount == 101, "Number of SFML keys has changed");
        #undef KB_MAP
    }

    std::string mapInstance(sf::Keyboard::Key key)
    {
        if (EventMap::umap.count(key))
            return EventMap::umap[key];
        else
            throw StringConversionException("No match string found");
    }
};

std::string toString(sf::Keyboard::Key key)
{
    static KeyEventMap k;
    return k.mapInstance(key);
}

// ------------------------------------------------------------------

class MouseButtonEventMap : public EventMap
{
public:
    MouseButtonEventMap(){
#define MB_MAP(identifier) INSERT_MAPPING(Mouse, identifier)
        MB_MAP(Left);
        MB_MAP(Right);
        MB_MAP(Middle);
        MB_MAP(XButton1);
        MB_MAP(XButton2);
#undef MB_MAP
    }

    std::string mapInstance(sf::Mouse::Button btn)
    {
        if (EventMap::umap.count(btn))
            return EventMap::umap[btn];
        else
            throw StringConversionException("No match string found");
    }
};

std::string toString(sf::Mouse::Button btn)
{
    static MouseButtonEventMap m;
    return m.mapInstance(btn);
}

// ------------------------------------------------------------------

class MouseWheelEventMap : public EventMap
{
public:
    MouseWheelEventMap(){
#define MW_MAP(identifier) INSERT_MAPPING(Mouse, identifier)
        MW_MAP(VerticalWheel);
        MW_MAP(HorizontalWheel);
#undef MW_MAP
    }

    std::string mapInstance(sf::Mouse::Wheel wh)
    {
        if (EventMap::umap.count(wh))
            return EventMap::umap[wh];
        else
            throw StringConversionException("MouseWheelEventMap::mapInstance(sf::Mouse::Wheel): No match string found");
    }
};

std::string toString(sf::Mouse::Wheel wh)
{
    static MouseWheelEventMap m;
    return m.mapInstance(wh);
}
