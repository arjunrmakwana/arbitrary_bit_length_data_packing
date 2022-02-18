# arbitrary_bit_length_data_packing

Processors usually have a fixed smallest word sie that you can access. This is usually a multiple
of 8 bits in most modern architecutres. So lets say you want to store some data that you know 
requires only 10 bits. But for that, you will end up using 16 bits. While for most cases this
is not an issue, it is an issue in case of compression algorithms and large data communication.

There are times when you want to access memory at some arbitrary precision like in case of storing
compressed data. That is what this code does.

This program takes 16 bit unsigned integer (can be any 16 bit data) and stores it at arbitrary precision
(defined by a macro) in a buffer. 

Such kind of data packing is useful for compression algorithms. This particular data packing
algorithm was written for LZW lossless compression algorithm and packs data in chunks of size
defined by the macro CODE_LENGTH.

I have also attached a diagram using which I wrote the algorithm to get a better idea behind the working of the algorithm.

Happy to answer questions :)
