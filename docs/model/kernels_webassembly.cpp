
#include <stdlib.h>
#include <math.h>

float static_buffer[87314812];
float* dynamic_buffer = nullptr;

int meta_buf_0[] = {67445068,74469756,1,3,448,448,448,448,3,3,1,1,1,1,1,1};
int meta_buf_1[] = {74469756,67435520,68047228,200704,32,27};
int meta_buf_2[] = {67445036,67445004,68047228,68047228,32,32,32,200704,1036831949};
int meta_buf_3[] = {68047228,85709180,1,448,448,32,224,224,2,2,2,2,0,0};
int meta_buf_4[] = {85709180,71258492,1,32,224,224,224,224,3,3,1,1,1,1,1,1};
int meta_buf_5[] = {71258492,67396608,68047228,50176,64,288};
int meta_buf_6[] = {67444812,67444748,68047228,68047228,64,64,64,50176,1036831949};
int meta_buf_7[] = {68047228,76878204,1,224,224,64,112,112,2,2,2,2,0,0};
int meta_buf_8[] = {76878204,69652860,1,64,112,112,112,112,3,3,1,1,1,1,1,1};
int meta_buf_9[] = {69652860,67216384,68047228,12544,128,576};
int meta_buf_10[] = {67443980,67444364,68047228,68047228,128,128,128,12544,1036831949};
int meta_buf_11[] = {68047228,67415040,69652860,12544,64,128};
int meta_buf_12[] = {67444876,67444940,69652860,69652860,64,64,64,12544,1036831949};
int meta_buf_13[] = {69652860,70455676,1,64,112,112,112,112,3,3,1,1,1,1,1,1};
int meta_buf_14[] = {70455676,67290112,68047228,12544,128,576};
int meta_buf_15[] = {67444492,67444620,68047228,68047228,128,128,128,12544,1036831949};
int meta_buf_16[] = {68047228,72462716,1,112,112,128,56,56,2,2,2,2,0,0};
int meta_buf_17[] = {72462716,68850044,1,128,56,56,56,56,3,3,1,1,1,1,1,1};
int meta_buf_18[] = {68850044,66364416,68047228,3136,256,1152};
int meta_buf_19[] = {67442188,67442700,68047228,68047228,256,256,256,3136,1036831949};
int meta_buf_20[] = {68047228,67363840,68850044,3136,128,256};
int meta_buf_21[] = {67444236,67444108,68850044,68850044,128,128,128,3136,1036831949};
int meta_buf_22[] = {68850044,69251452,1,128,56,56,56,56,3,3,1,1,1,1,1,1};
int meta_buf_23[] = {69251452,66659328,68047228,3136,256,1152};
int meta_buf_24[] = {67443468,67441932,68047228,68047228,256,256,256,3136,1036831949};
int meta_buf_25[] = {68047228,70254972,1,56,56,256,28,28,2,2,2,2,0,0};
int meta_buf_26[] = {70254972,68448636,1,256,28,28,28,28,3,3,1,1,1,1,1,1};
int meta_buf_27[] = {68448636,61341696,68047228,784,512,2304};
int meta_buf_28[] = {67437920,67436384,68047228,68047228,512,512,512,784,1036831949};
int meta_buf_29[] = {68047228,67085312,68448636,784,256,512};
int meta_buf_30[] = {67443724,67443212,68448636,68448636,256,256,256,784,1036831949};
int meta_buf_31[] = {68448636,68649340,1,256,28,28,28,28,3,3,1,1,1,1,1,1};
int meta_buf_32[] = {68649340,63700992,68047228,784,512,2304};
int meta_buf_33[] = {67440992,67439456,68047228,68047228,512,512,512,784,1036831949};
int meta_buf_34[] = {68047228,66954240,68448636,784,256,512};
int meta_buf_35[] = {67442956,67442444,68448636,68448636,256,256,256,784,1036831949};
int meta_buf_36[] = {68448636,68649340,1,256,28,28,28,28,3,3,1,1,1,1,1,1};
int meta_buf_37[] = {68649340,62521344,68047228,784,512,2304};
int meta_buf_38[] = {67438432,67436896,68047228,68047228,512,512,512,784,1036831949};
int meta_buf_39[] = {68047228,68448636,1,28,28,512,14,14,2,2,2,2,0,0};
int meta_buf_40[] = {68448636,68649340,1,512,14,14,14,14,3,3,1,1,1,1,1,1};
int meta_buf_41[] = {68649340,47185920,68448636,196,1024,4608};
int meta_buf_42[] = {67429376,67425280,68448636,68448636,1024,1024,1024,196,1036831949};
int meta_buf_43[] = {68448636,64880640,68649340,196,512,1024};
int meta_buf_44[] = {67439968,67438944,68649340,68649340,512,512,512,196,1036831949};
int meta_buf_45[] = {68649340,68749692,1,512,14,14,14,14,3,3,1,1,1,1,1,1};
int meta_buf_46[] = {68749692,51904512,68448636,196,1024,4608};
int meta_buf_47[] = {67430400,67428352,68448636,68448636,1024,1024,1024,196,1036831949};
int meta_buf_48[] = {68448636,65404928,68649340,196,512,1024};
int meta_buf_49[] = {67440480,67437408,68649340,68649340,512,512,512,196,1036831949};
int meta_buf_50[] = {68649340,68749692,1,512,14,14,14,14,3,3,1,1,1,1,1,1};
int meta_buf_51[] = {68749692,56623104,68448636,196,1024,4608};
int meta_buf_52[] = {67423232,67427328,68448636,68448636,1024,1024,1024,196,1036831949};
int meta_buf_53[] = {68448636,68649340,1,1024,14,14,14,14,3,3,1,1,1,1,1,1};
int meta_buf_54[] = {68649340,28311552,68448636,196,1024,9216};
int meta_buf_55[] = {67424256,67432448,68448636,68448636,1024,1024,1024,196,1036831949};
int meta_buf_56[] = {68448636,68850044,1,1024,14,14,14,14,3,3,1,1,1,1,1,1};
int meta_buf_57[] = {68850044,37748736,68649340,196,1024,9216};
int meta_buf_58[] = {67431424,67434496,68649340,68649340,1024,1024,1024,196,1036831949};
int meta_buf_59[] = {68047228,68850044,2,1,512,2048,28,14,28,14};
int meta_buf_60[] = {68047228,4,2,68850044,68649340,1,1,602112,43008,3072,1,602112,43008,3072,1,1,14,14,2048,1,14,14,1024,0,2048};
int meta_buf_61[] = {68047228,68649340,1,3072,14,14,14,14,3,3,1,1,1,1,1,1};
int meta_buf_62[] = {68649340,0,68047228,196,1024,27648};
int meta_buf_63[] = {67426304,67433472,68047228,68047228,1024,1024,1024,196,1036831949};
int meta_buf_64[] = {68047228,65929216,68247932,196,425,1024};
int meta_buf_65[] = {67441504,68247932,68047228,425,196,425,196};
int meta_buf_66[] = {68047228,68131508,83300};
int meta_buf_67[] = {68131508,4,6,68130528,68128568,68129548,68127588,68048208,68049188,1,1,1,1,1,1,16660,14,1,196,16660,14,1,196,16660,14,1,196,16660,14,1,196,16660,14,1,196,16660,14,1,196,5,14,14,1,5,14,14,1,5,14,14,1,5,14,14,1,5,14,14,1,5,14,14,80,0,196,392,588,784,980};
int meta_buf_68[] = {68048208,68047228,980};
int meta_buf_69[] = {68127588,68047212,68048208,196,196,5,196,1032997157};
int meta_buf_70[] = {68130528,68047196,68127588,14,14,14,70,1032997157};
int meta_buf_71[] = {68129548,68047220,68206968,196,196,5,196,1032997157};
int meta_buf_72[] = {68128568,68047180,68207948,14,196,14,196,14,5,14,1032997157};
int meta_buf_73[] = {68049188,68128568,78400};
int meta_buf_74[] = {68128568,68128568,980,80};
int meta_buf_75[] = {68128568,68049188,78400};
int* meta_buffers[] = {meta_buf_0,meta_buf_1,meta_buf_2,meta_buf_3,meta_buf_4,meta_buf_5,meta_buf_6,meta_buf_7,meta_buf_8,meta_buf_9,meta_buf_10,meta_buf_11,meta_buf_12,meta_buf_13,meta_buf_14,meta_buf_15,meta_buf_16,meta_buf_17,meta_buf_18,meta_buf_19,meta_buf_20,meta_buf_21,meta_buf_22,meta_buf_23,meta_buf_24,meta_buf_25,meta_buf_26,meta_buf_27,meta_buf_28,meta_buf_29,meta_buf_30,meta_buf_31,meta_buf_32,meta_buf_33,meta_buf_34,meta_buf_35,meta_buf_36,meta_buf_37,meta_buf_38,meta_buf_39,meta_buf_40,meta_buf_41,meta_buf_42,meta_buf_43,meta_buf_44,meta_buf_45,meta_buf_46,meta_buf_47,meta_buf_48,meta_buf_49,meta_buf_50,meta_buf_51,meta_buf_52,meta_buf_53,meta_buf_54,meta_buf_55,meta_buf_56,meta_buf_57,meta_buf_58,meta_buf_59,meta_buf_60,meta_buf_61,meta_buf_62,meta_buf_63,meta_buf_64,meta_buf_65,meta_buf_66,meta_buf_67,meta_buf_68,meta_buf_69,meta_buf_70,meta_buf_71,meta_buf_72,meta_buf_73,meta_buf_74,meta_buf_75};

extern "C" void init() {
    //static_buffer = (float*)malloc(87314812 * sizeof(float));
}

extern "C" float* get_static_buffer(void) {
    return static_buffer;
}

extern "C" float* allocate_dynamic_buffer(int count) {
    if (dynamic_buffer) {
        free(dynamic_buffer);
        dynamic_buffer = nullptr;
    }
    dynamic_buffer = (float*)malloc(count * sizeof(float));
    return dynamic_buffer;
}

extern "C" float* get_dynamic_buffer(void) {
    return dynamic_buffer;
}
extern "C" void set_placeholder_value(int kernel_order, int offset, int value) {
    meta_buffers[kernel_order][offset] = value;
}

void im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(const int * meta_buffer)
{
    const float *im = (static_buffer + meta_buffer[0]);
    float *col = (static_buffer + meta_buffer[1]);

    const int N = meta_buffer[2];
    const int C1 = meta_buffer[3];
    const int H1 = meta_buffer[4];
    const int W1 = meta_buffer[5];
    const int H2 = meta_buffer[6];
    const int W2 = meta_buffer[7];
    const int KH = meta_buffer[8];
    const int KW = meta_buffer[9];
    const int DH = meta_buffer[10];
    const int DW = meta_buffer[11];
    const int SH = meta_buffer[12];
    const int SW = meta_buffer[13];
    const int PH = meta_buffer[14];
    const int PW = meta_buffer[15];

    for (int gid = 0; gid < N*H2*W2*KH*KW*C1; gid += 1) {
        const int c1 = gid % C1;
        const int kw = gid / C1 % KW;
        const int kh = gid / C1 / KW % KH;
        const int w2 = gid / C1 / KW / KH % W2;
        const int h2 = gid / C1 / KW / KH / W2 % H2;
        const int  n = gid / C1 / KW / KH / W2 / H2;
        
        const int h1 = h2 * SH - PH + kh * DH;
        const int w1 = w2 * SW - PW + kw * DW;

        col[gid] = (h1 < 0 || h1 >= H1 || w1 < 0 || w1 >= W1) ? 0 : im[((n*H1+h1)*W1+w1)*C1+c1];
    }
}


#ifndef INCLUDE_EIGEN
#define INCLUDE_EIGEN
#include <Eigen/Dense>
#endif

void sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(const int * meta_buffer)
{
    float *A = (static_buffer + meta_buffer[0]);
    float *B = (static_buffer + meta_buffer[1]);
    float *C = (static_buffer + meta_buffer[2]);

    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> > a_mat(A, meta_buffer[3], meta_buffer[5]);
    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> > b_mat(B, meta_buffer[5], meta_buffer[4]);
    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> > c_mat(C, meta_buffer[3], meta_buffer[4]);

    c_mat.noalias() = a_mat * b_mat;
}


void mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    float * v4 = (static_buffer + meta_buffer[3]);
    const int v5 = meta_buffer[4];
    const int v6 = meta_buffer[5];
    const int D0 = meta_buffer[6];
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9 * v7;
            }
            float v11;
            {
                v11 = v10 + v8;
            }
            float v12;
            {
                float slope = *((float *)(&meta_buffer[8]));
                v12 = v11 > 0 ? v11 : (v11 * slope);
            }
            v4[d0 + d1*v6] = v12;
        }
    }
}


void maxpooling2d_6f91142d9d2142f2bf5f971bbd42a9177ff9f0a3847ed38923b3b331(const int * meta_buffer)
{
    const float *X = (static_buffer + meta_buffer[0]);
    float *Y = (static_buffer + meta_buffer[1]);
    const int N = meta_buffer[2];
    const int H1 = meta_buffer[3];
    const int W1 = meta_buffer[4];
    const int C = meta_buffer[5];
    const int H2 = meta_buffer[6];
    const int W2 = meta_buffer[7];
    const int KH = meta_buffer[8];
    const int KW = meta_buffer[9];
    const int SH = meta_buffer[10];
    const int SW = meta_buffer[11];
    const int PH = meta_buffer[12];
    const int PW = meta_buffer[13];

    for (int gid = 0; gid < N * H2 * W2 * C; gid += 1) {
        const int c = gid % C;
        const int w2 = gid / C % W2;
        const int h2 = gid / C / W2 % H2;
        const int n = gid / C / W2 / H2;

        float v = -1e7;
        for (int kh = 0; kh < KH; kh++) {
            const int h1 = h2 * SH - PH + kh;
            if (h1 < 0 || h1 >= H1) continue;
            
            for (int kw = 0; kw < KW; kw++) {
                const int w1 = w2 * SW - PW + kw;
                if (w1 < 0 || w1 >= W1) continue;

                v = v > X[((n * H1 + h1) * W1 + w1) * C + c] ? v : X[((n * H1 + h1) * W1 + w1) * C + c];
            }
        }

        Y[gid] = v;
    }
}


void space2depth_2b7899e1542308a244192744da9b6ea95606088c06e0f63cea01bc54(const int * meta_buffer)
{
    const float *x = (static_buffer + meta_buffer[0]);
    float *y = (static_buffer + meta_buffer[1]);
    const int r = meta_buffer[2];

    const int N = meta_buffer[3];
    const int C1 = meta_buffer[4];
    const int C2 = meta_buffer[5];
    const int H1 = meta_buffer[6];
    const int H2 = meta_buffer[7];
    const int W1 = meta_buffer[8];
    const int W2 = meta_buffer[9];

    for (int gid = 0; gid < N*H1*W1*C1; gid += 1) {
        const int c1 = gid % C1;
        const int w1 = gid / C1 % W1;
        const int h1 = gid / C1 / W1 % H1;
        const int n = gid / C1 / W1 / H1;
        const int w2 = w1 / r;
        const int h2 = h1 / r;
        const int c2 = c1 + (w1 % r) * C1 + (h1 % r) * C1 * r;
        y[((n*H2+h2)*W2+w2)*C2+c2] = x[gid];
    }
}


void concat_7d93c94d0d8cf6221275a915863ab6c2a3c5444b9d2d3cb83d03d467(const int * meta_buffer)
{
    float *y = (static_buffer + meta_buffer[0]);
    const int N = meta_buffer[2];
    const int D = meta_buffer[1];
    const int *y_offsets = (&(meta_buffer[23]));
    const int *x_shapes = (&(meta_buffer[15]));
    const int *x_strides_in_y = (&(meta_buffer[7]));
    
    int x_index = 0;
    
    for (int n = 0; n < N; n++) {
        const float *x = (meta_buffer[3+2+ (n)] ? static_buffer : dynamic_buffer) + meta_buffer[3 + (n)];
        const int y_offset = y_offsets[n];
        const int *x_shape = x_shapes + n * D;
        const int *x_stride_in_y = x_strides_in_y + n * D;
        
        int x_size = 1;
        for (int d = 0; d < D; d++) {
            x_size *= x_shape[d];
        }
        
        while (x_index < x_size) { 
            int y_index = y_offset;
            int s = x_index;
            for (int d = D-1; d >= 0; d--) {
                y_index += x_stride_in_y[d] * (s % x_shape[d]);
                s /= x_shape[d];
            }
        
            y[y_index] = x[x_index];
            
            x_index++;
        }
        
        x_index -= x_size;
    }
}


void mergedelementwise_86198e4b7f4d97c242f374dac3bbaf5cd3b479f093e944e4c347290e(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int D0 = meta_buffer[5];
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            float v9;
            {
                v9 = v8;
            }
            v3[d0*v5 + d1] = v9;
        }
    }
}


void reshape_f6c88dc1fd9479f62d789912530e6a5c7c51c73de368540e8b8e1ceb(const int * meta_buffer )
{
    const float *x = (static_buffer + meta_buffer[0]);
    float *y = (static_buffer + meta_buffer[1]);

    const int N = meta_buffer[2];

    for (int gid = 0; gid < N; gid += 1) {
        y[gid] = x[gid];
    }
}


void splitaxis_631b90b406314c68e9081605b5183a6d05b157438276f2a725520994(const int * meta_buffer)
{
    const float *x = (static_buffer + meta_buffer[0]);
    const int N = meta_buffer[2];
    const int D = meta_buffer[1];
    const int *x_offsets = (&(meta_buffer[63]));
    const int *y_shapes = (&(meta_buffer[39]));
    const int *y_strides_in_x = (&(meta_buffer[15]));
    
    int y_index = 0;
    
    for (int n = 0; n < N; n++) {
        float *y = (meta_buffer[3+6+ (n)] ? static_buffer : dynamic_buffer) + meta_buffer[3 + (n)];
        const int x_offset = x_offsets[n];
        const int *y_shape = y_shapes + n * D;
        const int *y_stride_in_x = y_strides_in_x + n * D;
        
        int y_size = 1;
        for (int d = 0; d < D; d++) {
            y_size *= y_shape[d];
        }
        
        while (y_index < y_size) { 
            int x_index = x_offset;
            int s = y_index;
            for (int d = D-1; d >= 0; d--) {
                x_index += y_stride_in_x[d] * (s % y_shape[d]);
                s /= y_shape[d];
            }
        
            y[y_index] = x[x_index];
            
            y_index++;
        }
        
        y_index -= y_size;
    }
}


void sigmoid_b09ad8d2aaa45374f91606d97341758ffad4e85382865481c73cec7e(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    float * v2 = (static_buffer + meta_buffer[1]);
    const int D0 = meta_buffer[2];
    int d0;
    for (d0 = 0; d0 < D0; d0 += 1) {
        const float v3 = v1[d0];
        float v4;
        {
            v4 = tanh(0.5f * v3) * 0.5f + 0.5f;
        }
        v2[d0] = v4;
    }
}


void mergedelementwise_6b852a83b598876641fc371e7158bbd070439e14227db7a1c00f7dd3(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int D0 = meta_buffer[5];
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v1[d0*v4 + d1];
            float v8;
            {
                v8 = exp(v7);
            }
            float v9;
            {
                v9 = v8 * v6;
            }
            float v10;
            {
                float value = *((float *)(&meta_buffer[7]));
                v10 = v9 * value;
            }
            v3[d0*v5 + d1] = v10;
        }
    }
}


void mergedelementwise_42155e740b4ed08c6314b95555ee287d4393009ea1bfb965a77932ae(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int D0 = meta_buffer[5];
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v1[d0 + d1*v4];
            float v8;
            {
                v8 = tanh(0.5f * v7) * 0.5f + 0.5f;
            }
            float v9;
            {
                v9 = v8 + v6;
            }
            float v10;
            {
                float value = *((float *)(&meta_buffer[7]));
                v10 = v9 * value;
            }
            v3[d0 + d1*v5] = v10;
        }
    }
}


void mergedelementwise_a42f7caf2f1afe28e1faa1d31225dc9c83018682407c96a758e3fb11(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int v6 = meta_buffer[5];
    const int v7 = meta_buffer[6];
    const int D0 = meta_buffer[7];
    const int D1 = meta_buffer[8];
    const int D2 = meta_buffer[9];
    int d0;
    for (d0 = 0; d0 < D0; d0 += 1) {
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 % (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? (1 / 8) : 1)) {
            int d2;
            for (d2 = ((1 > 8) ? (0 / (1 / 8)) : 0); d2 < D2; d2 += ((1 > 8) ? 8 : 1)) {
                const float v9 = v1[d0*v4 + d1*v5 + d2];
                float v10;
                {
                    v10 = tanh(0.5f * v9) * 0.5f + 0.5f;
                }
                float v11;
                {
                    v11 = v10 + v8;
                }
                float v12;
                {
                    float value = *((float *)(&meta_buffer[10]));
                    v12 = v11 * value;
                }
                v3[d0*v6 + d1*v7 + d2] = v12;
            }
        }
    }
}


void softmax_be4c2fae32b9326b0ca891226ac9234de828aecba508a30394d8a57e(const int * meta_buffer)
{
    const float *X = (static_buffer + meta_buffer[0]);
    float *Y = (static_buffer + meta_buffer[1]);
    const int N = meta_buffer[2];
    const int C = meta_buffer[3];

    for (int n = 0; n < N; n++) {
        float set_max = X[n * C];
        for (int c = 0; c < C; c++) {
            float val = X[n * C + c];
            if (val > set_max) {
                set_max = val;
            }
        }

        float sum_exp = 0.0F;
        for (int c = 0; c < C; c++) {
            float val = X[n * C + c];
            float exp_x = expf(val - set_max);
            sum_exp += exp_x;
            Y[n * C + c] = exp_x;
        }

        for (int c = 0; c < C; c++) {
            Y[n * C + c] /= sum_exp;
        }
    }
}

extern "C" void run() {
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_0);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_1);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_2);
maxpooling2d_6f91142d9d2142f2bf5f971bbd42a9177ff9f0a3847ed38923b3b331(meta_buf_3);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_4);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_5);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_6);
maxpooling2d_6f91142d9d2142f2bf5f971bbd42a9177ff9f0a3847ed38923b3b331(meta_buf_7);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_8);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_9);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_10);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_11);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_12);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_13);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_14);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_15);
maxpooling2d_6f91142d9d2142f2bf5f971bbd42a9177ff9f0a3847ed38923b3b331(meta_buf_16);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_17);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_18);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_19);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_20);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_21);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_22);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_23);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_24);
maxpooling2d_6f91142d9d2142f2bf5f971bbd42a9177ff9f0a3847ed38923b3b331(meta_buf_25);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_26);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_27);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_28);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_29);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_30);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_31);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_32);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_33);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_34);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_35);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_36);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_37);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_38);
maxpooling2d_6f91142d9d2142f2bf5f971bbd42a9177ff9f0a3847ed38923b3b331(meta_buf_39);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_40);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_41);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_42);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_43);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_44);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_45);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_46);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_47);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_48);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_49);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_50);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_51);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_52);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_53);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_54);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_55);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_56);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_57);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_58);
space2depth_2b7899e1542308a244192744da9b6ea95606088c06e0f63cea01bc54(meta_buf_59);
concat_7d93c94d0d8cf6221275a915863ab6c2a3c5444b9d2d3cb83d03d467(meta_buf_60);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_61);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_62);
mergedelementwise_a0e44da8b3e9b9923c733e8434e0853de3a2eb3e5c9adc940e51d4f4(meta_buf_63);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_64);
mergedelementwise_86198e4b7f4d97c242f374dac3bbaf5cd3b479f093e944e4c347290e(meta_buf_65);
reshape_f6c88dc1fd9479f62d789912530e6a5c7c51c73de368540e8b8e1ceb(meta_buf_66);
splitaxis_631b90b406314c68e9081605b5183a6d05b157438276f2a725520994(meta_buf_67);
sigmoid_b09ad8d2aaa45374f91606d97341758ffad4e85382865481c73cec7e(meta_buf_68);
mergedelementwise_6b852a83b598876641fc371e7158bbd070439e14227db7a1c00f7dd3(meta_buf_69);
mergedelementwise_42155e740b4ed08c6314b95555ee287d4393009ea1bfb965a77932ae(meta_buf_70);
mergedelementwise_6b852a83b598876641fc371e7158bbd070439e14227db7a1c00f7dd3(meta_buf_71);
mergedelementwise_a42f7caf2f1afe28e1faa1d31225dc9c83018682407c96a758e3fb11(meta_buf_72);
reshape_f6c88dc1fd9479f62d789912530e6a5c7c51c73de368540e8b8e1ceb(meta_buf_73);
softmax_be4c2fae32b9326b0ca891226ac9234de828aecba508a30394d8a57e(meta_buf_74);
reshape_f6c88dc1fd9479f62d789912530e6a5c7c51c73de368540e8b8e1ceb(meta_buf_75);

}

