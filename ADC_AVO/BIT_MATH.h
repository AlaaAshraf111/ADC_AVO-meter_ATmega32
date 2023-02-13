
#define SET_BIT(byte,n) (byte|=(1<<n))
#define CLR_BIT(byte,n) (byte &=(~(1<<n)))
#define TOGGLE(byte,n) (byte ^=(1<<n))
#define GET_BIT(byte,n) (byte = ((byte>>n)&1))
