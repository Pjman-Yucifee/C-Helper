#include <cHelper.h>

    struct {
        io_port_t type;
        UART_HandleTypeDef* uart;
    }   static std_io;

    struct {
        char point;
        char major;
        char minor;
        char patch;
        char batch[10];
        char build[10];
    }   static version;

    char* getVersion(void) {
        return "";
    }

    void setVersion(char point, char major, char minor, char patch, char batch[10], char build[10]) {
        version.point = point;
        version.major = major;
        version.minor = minor;
        version.patch = patch;
        strcpy(version.batch, batch);
        strcpy(version.build, build);
    }

#ifdef __GNUC__
    int __io_putchar(int ch) {
#else
    int fputc(int ch, FILE *f) {
#endif
        switch (std_io.type) {
            case UART:
            HAL_UART_Transmit(std_io.uart, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
            break;
            default:
            break;
        }
        return ch;
    }

    void io_init(io_port_t type, void* handle) {
        switch (type) {
            case UART:
            std_io.type = UART; std_io.uart = handle;
            break;
            default:
            std_io.type = NONE; std_io.uart = 0;
        }
    }

    unsigned crc32_gen(void* data, unsigned size) {
        return 0;
    }

    inline void HAL_GPIO_HiPin(GPIO_HandleTypeDef* gpio) {
        HAL_GPIO_WritePin(gpio->port, gpio->pin, GPIO_PIN_SET);
    }

    inline void HAL_GPIO_LoPin(GPIO_HandleTypeDef* gpio) {
        HAL_GPIO_WritePin(gpio->port, gpio->pin, GPIO_PIN_RESET);
    }

    inline void HAL_GPIO_ToggPin(GPIO_HandleTypeDef* gpio) {
        HAL_GPIO_TogglePin(gpio->port, gpio->pin);
    }

    inline void HAL_GPIO_TrigPin(GPIO_HandleTypeDef* gpio, uint32_t milliseconds) {
        HAL_GPIO_TogglePin(gpio->port, gpio->pin);
        HAL_Delay(milliseconds);
        HAL_GPIO_TogglePin(gpio->port, gpio->pin);
    }
