#include "Input.h"

Aggrotech::Input::Input(bool isButtonDown)
    : isButtonDown(isButtonDown)
{

}

bool Aggrotech::Input::IsButtonDown() const
{
    return isButtonDown;
}
