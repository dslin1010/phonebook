reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

<<<<<<< HEAD
plot [:][:0.100]'output.txt' using 2:xtic(1) with histogram title 'original',\
'' using 3:xtic(1) with histogram title 'entry',\
'' using 4:xtic(1) with histogram title 'hash',\
'' using 5:xtic(1) with histogram title 'hash with memory pool',\
'' using ($0-0.1):($2+0.0050):2 with labels title ' ',\
'' using ($0+0.1):($3+0.0045):3 with labels title ' ',\
'' using ($0+0.2):($4+0.0020):4 with labels title ' ',\
'' using ($0+0.5):($5+0.0020):5 with labels title ' '

=======
plot [:][:0.100]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.06):($2+0.001):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'optimized'  , \
'' using ($0+0.3):($3+0.0015):3 with labels title ' '
>>>>>>> parent of 418abfb... add hash funtion and shrink entry size
