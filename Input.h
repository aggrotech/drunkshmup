#pragma once

namespace Aggrotech
{
    class Input
    {
    public:

        Input(bool isButtonDown);

        bool IsButtonDown() const;

    private:

        bool isButtonDown;
    };
}
