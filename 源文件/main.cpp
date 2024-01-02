#include "home_page.h"

int main()
{
    Load_account();
    Load_post();

    Home h;
    h.home_operate();

    Save_account();
    Save_post();
    return 0;
}
