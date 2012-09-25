#ifndef _GPIO_MSP430_HPP
#define _GPIO_MSP430_HPP

#include <gpio_base.hpp>
#include <msp430.h>


template <int in_reg_, int out_reg_, int dir_reg_, typename width_>
class Port : public IPort
{
public:
    static const int in_reg = in_reg_;
    static const int out_reg = out_reg_;
    static const int dir_reg = dir_reg_;
    typedef width_ width;
};

typedef Port<P1IN_, P1OUT_, P1DIR_, uint8_t> P1;
typedef Port<P2IN_, P2OUT_, P2DIR_, uint8_t> P2;

template <class port_, class bit>
class Pin : IPin
{
public:
    typedef port_ port;

    static uint8_t value()
    {
        return *(volatile uint8_t*)port::in_reg & bit::value;
    }
    static void high()
    {
        *(volatile uint8_t*)port::out_reg |= bit::value;
    }
    static void low()
    {
        *(volatile uint8_t*)port::out_reg &= ~bit::value;
    }
    static void output()
    {
        *(volatile uint8_t*)port::dir_reg |= bit::value;
    }
    static void input()
    {
        *(volatile uint8_t*)port::dir_reg &= ~bit::value;
    }
};

#endif //_GPIO_MSP430_HPP
