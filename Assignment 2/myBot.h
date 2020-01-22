//Wrritten by Bailey Ivancic
//Contains all functions used in Assignment 2

//bot_functions.c
int maxSell(struct location* vendor, int cargo); 
int maxBuy(struct bot* b, struct location* vendor); 
struct location* sellMove(struct bot* b, struct commodity* item, int amount);
struct location* buyMove(struct bot* b);
int lookFuel(struct location *b);
void getFuel(struct bot* b, int *action, int* n);
int avgFuelPrice(struct location* runner);
int distance (struct location* runner, struct location* place);
int closeBuyer(struct bot* b);
int closeDump(struct bot* b);

//my_bot.c
char *get_bot_name(void);
void get_action(struct bot *b, int *action, int *n);
