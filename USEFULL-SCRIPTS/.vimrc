set number
syntax on
set tabstop=4
set autoindent
set softtabstop=4
set cursorline
set cursorcolumn
set hlsearch
set smartcase

:set  t_Co=256


inoremap " ""<left>
inoremap ' ''<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O
inoremap ;; <ESC>

:iabbrev cpp@ #include<bits/stdc++.h><CR>using namespace std;<CR><CR>int main(<Right>{<CR><Tab><CR><Up>
