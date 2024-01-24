ferris/sweep:default:dfu-split-right
ferris/sweep:default:dfu-split-left

make ferris/sweep:diegoDefault:dfu-split-left
make ferris/sweep:diegoDefault:dfu-split-right

qmk build -kb ferris/sweep -kb diegoDefault
qmk compile -kb ferris/sweep -kb diegoDefault


