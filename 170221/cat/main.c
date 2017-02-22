/*
 * =============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main test.
 *
 *        Created:  12/31/2012 01:00:43 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include <stdio.h>

#include "animal-base.h"
#include "dog.h"
#include "cat.h"

int main(int argc, const char *argv[])
{
    cat_t *cat = cat_init();
    dog_t *dog = dog_init();

    /* dog 类测试 */
/*    animal_eat(&dog->base, "bones");
    animal_walk(&dog->base, 5);
    animal_talk(&dog->base, "wuang wuang wuang..."); */

    /* cat 类测试 */
    animal_eat(&cat->base, "fish");
    animal_walk(&cat->base, 3);
    animal_talk(&cat->base, "miao miao miao...");

}
