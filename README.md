# IMX6ULL Vehicle Terminal

基于IMX6ULL、嵌入式Linux和Qt开发的模块化智能车载终端。

本项目以IMX6ULL基础车载终端为起点，逐步实现界面导航、环境监测、音乐播放、系统设置、设备管理等功能，并为后续迁移到RK3588、接入Camera、多媒体处理、Wi-Fi和端侧AI推理预留架构。

## Hardware

- SoC: NXP i.MX6ULL
- Architecture: ARMv7 Cortex-A7
- Display: 1024 × 600, 32 bpp
- Touchscreen: Goodix
- Audio Codec: WM8960

## Software Environment

- Host OS: Ubuntu 18.04.2 LTS
- Target OS: Buildroot 2020.02
- Linux Kernel: 4.9.88
- Qt: 5.12.8
- Toolchain: arm-buildroot-linux-gnueabihf GCC 7.5.0

## Development Workflow

Windows VS Code  
→ FileZilla上传源码  
→ Ubuntu交叉编译  
→ ADB上传程序  
→ IMX6ULL开发板运行

## Project Structure

```text
imx6ull-vehicle-terminal/
├── src/                 Qt应用代码
│   ├── pages/           功能页面
│   ├── services/        业务服务
│   └── devices/         用户态设备访问
├── core/                纯C核心模块
├── include/             公共C头文件
├── resources/           图片和样式资源
├── drivers/             Linux设备驱动
├── scripts/             编译、部署和启动脚本
├── docs/                项目文档
├── experiments/         环境验证和实验代码
└── VehicleTerminal.pro  qmake工程文件
