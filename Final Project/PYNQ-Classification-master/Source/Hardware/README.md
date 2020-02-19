
### Guide for Regenerating Vivado HLS and Vivado Projects


In this project, the CNN topology is packaged as a Vivado HLS block design, which is then included in the Vivado project. Hence, we should regenerate Vivado HLS project first, before regenerating the overall Vivado project.

- Regenerate Vivado HLS Project

Open Vivado HLS command tool. cd to PYNQ-Classification/Source/hw/script_design_flow/CIFAR_10_wrapper directory. Run the following command.

`vivado_hls -f run_cifar_10.tcl`


- Copy PYNQ Board Files to Your Vivado Installation

The default Vivado installation does not contain the PYNQ board files. Here we use the Arty-z7-20 board files, sinice it is also applicable to PYNQ board configuration. Just copy the PYNQ-Classification/tools/PYNQ_BOARD_FILES/arty-z7-20/ folder under (vivado_installation)/data/boards/board_files/ directory. Vivado should automatically detect new board files at restart.

- Regenerate Vivado Project

Open Vivado command tool. cd to PYNQ-Classification/Source/hw/base_project directory. Run the following command.

`vivado -source pynq_arch.tcl`

