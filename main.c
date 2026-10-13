#include <REG52.H>

/* ---------------- Configuration ---------------- */
#define PATTERN_DELAY_COUNT   15000UL
#define DEBOUNCE_COUNT        1000U
#define LED_PORT              P1
#define BTN_PORT              P2
#define NUM_LEDS              8
#define PAT3_REPEATS          5
#define BTN_COUNT  			  3

#define BTN_PRESSED(pin)      ((BTN_PORT & (1 << (pin))) == 0)

/* ---------------- Delays ---------------- */
static void debounce_delay(void)
{
    volatile unsigned int i;
    for (i = 0; i < DEBOUNCE_COUNT; i++);
}

static void pattern_delay(void)
{
    volatile unsigned long j;
    for (j = 0; j < PATTERN_DELAY_COUNT; j++);
}

/* ---------------- LED patterns ---------------- */

/* Single LED moving from bit 0 to bit 7 */
static void pattern_up(void)
{
    unsigned char i;
    for (i = 0; i < NUM_LEDS; i++)
    {
        LED_PORT = (unsigned char)(1 << i);
        pattern_delay();
    }
}

/* Single LED moving from bit 7 to bit 0 */
static void pattern_down(void)
{
    char i;
    for (i = NUM_LEDS - 1; i >= 0; i--)
    {
        LED_PORT = (unsigned char)(1 << i);
        pattern_delay();
    }
}

/* Alternating 0xAA / 0x55 blink */
static void pattern_alternate(void)
{
    unsigned char i;
    for (i = 0; i < PAT3_REPEATS; i++)
    {
        LED_PORT = 0xAA;
        pattern_delay();
        LED_PORT = 0x55;
        pattern_delay();
    }
}

/* ---------------- Button -> pattern table ---------------- */
typedef struct {
    unsigned char pin;          /* bit number on BTN_PORT */
    void (*action)(void);       /* pattern to run when the btn is pressed */
} ButtonMap;

static const ButtonMap code button_map[] = {
    { 0, pattern_up },
    { 2, pattern_down },
    { 3, pattern_alternate }
};

/* ---------------- Button handling ---------------- */
static void handle_button(const ButtonMap *btn)
{
    if (!BTN_PRESSED(btn->pin))
        return;
	
    debounce_delay();
    if (!BTN_PRESSED(btn->pin))
        return;

    btn->action();

    while (BTN_PRESSED(btn->pin));   /* wait for release */
    debounce_delay();
}

/* ---------------- Main ---------------- */
void main(void)
{
    unsigned char i;

    BTN_PORT = 0xFF;    /* inputs: write 1s to P2 */
    LED_PORT = 0x00;

    while (1)
    {
        for (i = 0; i < BTN_COUNT; i++)
            handle_button(&button_map[i]);
    }
}
