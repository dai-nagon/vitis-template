
extern "C" {

void krnl(const unsigned int *in1, // Read-Only Vector 1
          const unsigned int *in2, // Read-Only Vector 2
          unsigned int *out_r,     // Output Result
          int size                 // Size in integer
    ) {
    #pragma HLS INTERFACE m_axi port = in1 offset = slave bundle = gmem
    #pragma HLS INTERFACE m_axi port = in2 offset = slave bundle = gmem
    #pragma HLS INTERFACE m_axi port = out_r offset = slave bundle = gmem
    #pragma HLS INTERFACE s_axilite port = in1 bundle = control
    #pragma HLS INTERFACE s_axilite port = in2 bundle = control
    #pragma HLS INTERFACE s_axilite port = out_r bundle = control
    #pragma HLS INTERFACE s_axilite port = size bundle = control
    #pragma HLS INTERFACE s_axilite port = return bundle = control

    for (int i {}; i < size; ++i) {
        #pragma HLS PIPELINE
        out_r[i] = in1[i] + in2[i];
    }
}

}
