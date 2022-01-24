My personal build of dwm.

## Applied patches
- [centeredmaster](https://dwm.suckless.org/patches/centeredmaster/)
- [Cool autostart](https://dwm.suckless.org/patches/cool_autostart/)
- [default tag applications](https://dwm.suckless.org/patches/default_tag_apps/)
- [float border color](https://dwm.suckless.org/patches/float_border_color/)
- [fullgaps](https://dwm.suckless.org/patches/fullgaps/)
- [gapless grid layout](https://dwm.suckless.org/patches/gaplessgrid/)
- [movestack](https://dwm.suckless.org/patches/movestack/)
- [systray](https://dwm.suckless.org/patches/systray/)
- [viewontag](https://dwm.suckless.org/patches/viewontag/)
- [shiftview](https://lists.suckless.org/dev/1104/7590.html)

## Dependencies
### Fonts
- Source Code Pro
- Font Awesome (only if you want icons as tag indicators)

### Applications
All programs listed here are optional and can be replaced by any other program. They are only needed if you want to use my build of dwm as it is.
#### automatically started
- Nitrogen
- Alacritty
#### default tag applications
- Alacritty
- Firefox
- Pcmanfm
- Thunderbird
- Torbrowser
### keybindings
- Alacritty
- Dmenu

## Keybindings
### Navigation
keybinding             | functionality
-----------------------|---------------
Super+Shift+Control+q  | quit
Super+b                | toggle bar
Super+[Number]         | go to the tag with that number
Super+Shift+[Number]   | move active window and focus to the tag with that number
Super+0                | view all windows from all tags
Super+Shift+0          | move active window to all tags
Super+[,/.]            | move focus between screens
Super+Shift+[,/.]      | move active window to a different screen
Super+Tab              | switch focus between latest tags
Super+Shift+Enter      | move active window to master
Super+Shift+c          | close active window
Super+Shift+Space      | toggle floating for active window
Super+n                | go to the next tag
Super+p                | go to the previous tag

### Layouts
keybinding             | functionality
-----------------------|---------------
Super+t                | set layout to tiled mode ([]=)
Super+f                | set layout to floating mode (><>)
Super+m                | set layout to monocle mode/single window fullscreen ([M])
Super+u                | set layout to centered master mode (|M|)
Super+o                | set layout to centered floating master mode (>M>)
Super+g                | set layout to grid mode (###)
Super+Space            | toggle to the previous layout

### Applications
keybinding             | functionality
-----------------------|---------------
Super+Enter            | create new terminal
Super+Shift+d          | open dmenu
Super+s                | open default application for the current tag

### Focus
keybinding             | functionality
-----------------------|---------------
Super+j                | set focus 1 down in the stack
Super+k                | set focus 1 up in the stack
Super+Shift+j          | move current window 1 down in the stack
Super+Shift+k          | move current window 1 up in the stack
Super+h                | decrease master size
Super+l                | increase master size
Super+d                | decrease number of windows on master
Super+i                | increase number of windows on master
