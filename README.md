# bitwise_data_packing

This program takes 16 bit unsigned inegers and packs it densely to specified size in a buffer.

Such kind of data packing is useful for compression algorithms. This particular data packing
algorithm was written for LZW lossless compression algorithm and packs data in chunks of size
defined by the macro CODE_LENGTH.

I have also attached a diagram to get a better idea behind the working of the algorithm.
