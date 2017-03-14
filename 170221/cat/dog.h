/*
 * =============================================================================
 *
 *       Filename:  dog.h
 *
 *    Description:  dog class derived from animal base class.
 *
 *        Created:  12/31/2012 12:44:05 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include "animal-base.h"

typedef struct dog_s_ dog_t;

struct dog_s_ {
    animal_t base; /* 继承自 animal 基类 */

    /* 以下还可以添加与 dog 相关的属性和方法(函数指针), 如: */
    /* char *owner; // dog 的主人 */
    /* void (*hunt)(const char *rabbit); // 猎兔犬 */
};

extern dog_t * dog_init();
extern void dog_die(dog_t * dog);

