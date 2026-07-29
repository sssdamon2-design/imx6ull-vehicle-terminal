#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>

/*
 * 当 platform_device 与 platform_driver 匹配成功后，
 * Linux 驱动核心会调用 probe()。
 */
static int vehicle_dht11_probe(struct platform_device *pdev)
{
    dev_info(&pdev->dev, "vehicle DHT11 probe success\n");

    return 0;
}

/*
 * 当驱动被卸载，或者设备与驱动解除绑定时，
 * Linux 驱动核心会调用 remove()。
 */
static int vehicle_dht11_remove(struct platform_device *pdev)
{
    dev_info(&pdev->dev, "vehicle DHT11 remove\n");

    return 0;
}

/*
 * 设备树匹配表。
 *
 * 这里的 compatible 必须和设备树中的：
 *
 * compatible = "damon,vehicle-dht11";
 *
 * 完全一致。
 */
static const struct of_device_id vehicle_dht11_of_match[] = {
    { .compatible = "damon,vehicle-dht11" },
    { }
};

/*
 * 将设备树匹配表导出到内核模块信息中，
 * 便于内核和用户空间工具识别模块支持的设备。
 */
MODULE_DEVICE_TABLE(of, vehicle_dht11_of_match);

/*
 * 定义 platform_driver。
 */
static struct platform_driver vehicle_dht11_driver = {
    .probe = vehicle_dht11_probe,
    .remove = vehicle_dht11_remove,

    .driver = {
        .name = "vehicle-dht11",
        .of_match_table = vehicle_dht11_of_match,
    },
};

/*
 * 自动生成模块加载和卸载入口：
 *
 * 加载模块时：
 * platform_driver_register(&vehicle_dht11_driver)
 *
 * 卸载模块时：
 * platform_driver_unregister(&vehicle_dht11_driver)
 */
module_platform_driver(vehicle_dht11_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Damon");
MODULE_DESCRIPTION("Minimal platform driver for vehicle DHT11");
