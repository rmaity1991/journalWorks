#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define FEATURES 5
#define SAMPLES  100

float X[SAMPLES][FEATURES]={
    { 2.17865746e+00,  4.37302612e-01,  4.03630360e-01,
        -1.33919787e+00, -1.41728132e+00},
       {-3.95753103e-02, -4.16364350e-01, -1.97925873e+00,
        -4.16664893e-01,  7.27691481e-02},
       {-2.07553062e-02, -1.30397918e+00,  5.93848386e-01,
        -3.53855669e-02, -1.00460679e+00},
       {-4.80858205e-01, -4.73795237e-01, -1.07636917e+00,
         5.48138794e-01,  1.04546109e+00},
       { 6.41371634e-01, -2.05870107e+00, -4.87283764e-02,
         6.46307020e-01, -6.34562138e-01},
       {-1.84856786e-02, -7.19290852e-01, -6.75189450e-01,
        -9.42856817e-01, -3.07420109e-01},
       { 1.14098521e+00, -3.08436463e-02, -2.06203355e+00,
        -8.44949285e-02, -1.18738252e+00},
       { 2.52519182e-01, -5.39528368e-01,  8.66967836e-01,
        -1.32192132e+00, -7.48113087e-01},
       {-6.54321094e-01, -3.64163288e-01, -6.17387273e-01,
         9.47328976e-01,  3.64282809e-01},
       { 3.52979664e-01, -1.04954239e+00,  3.60082917e-01,
        -1.89272768e-01,  8.51277465e-01},
       {-5.83412360e-01,  9.87633189e-01, -9.52194188e-02,
        -7.06826416e-01,  3.01451724e-01},
       { 4.78704408e-01,  6.88514556e-01, -7.75354554e-01,
        -1.55302940e+00, -2.46973276e+00},
       {-5.89064753e-01, -5.29142387e-02, -1.01593983e+00,
         3.32125588e-01, -1.47756065e+00},
       {-8.93285194e-01, -4.35890561e-01,  4.84621954e-01,
         1.56728605e+00,  6.03741937e-02},
       { 7.63133872e-01, -6.31857274e-01,  1.33072527e+00,
        -1.89343014e+00,  9.27644555e-01},
       {-6.69400588e-01, -1.61823219e+00, -5.92481628e-01,
         1.80910167e-01,  7.67856578e-01},
       {-1.72493051e+00, -1.80154542e-01, -9.43144639e-01,
         1.15354004e+00, -1.53078090e+00},
       {-2.29313008e-01, -1.24832962e+00,  1.92513290e+00,
         3.72397063e-01, -1.64070972e-01},
       {-1.27977507e+00, -5.39284667e-01,  1.60629280e+00,
         6.98286512e-01,  1.32943690e-01},
       { 3.64314810e+00, -8.91774384e-01,  6.61409112e-01,
         4.88087732e-01,  5.04750059e-01},
       {-3.01588095e-01,  1.05293163e-01, -5.78125800e-02,
        -3.44531055e-01,  4.29221723e-01},
       {-1.07812754e+00, -1.05804981e+00, -4.17321782e-01,
        -8.53141216e-01, -6.56051718e-01},
       {-9.60974858e-01, -2.52866795e-01, -5.86136428e-01,
         9.53748237e-01, -2.60072822e-02},
       { 1.80637534e-01, -1.78458704e+00, -1.18257540e+00,
         3.06152868e-01, -1.69529796e+00},
       {-3.14617335e-01, -1.34073527e-01,  1.87546949e-01,
         1.64926000e+00, -1.82511441e+00},
       { 1.82306577e+00,  3.37828692e-01,  2.37176391e+00,
        -1.53196576e+00,  2.49614802e-01},
       {-8.32090141e-01,  1.14765475e-01, -6.64502257e-01,
         3.00812235e-02, -1.13571729e+00},
       { 3.95426083e-01, -8.05455321e-01,  8.90499667e-01,
         3.27144982e-01,  3.60054009e+00},
       {-3.93769550e-01,  5.61435263e-01,  2.59718256e-01,
         5.70304850e-01, -2.76223683e-01},
       {-1.88497577e-01, -1.68365332e+00,  2.50656596e-01,
        -6.23709141e-02,  1.86636730e-01},
       {-4.74747875e-01, -3.28185675e-01, -1.95198407e-01,
        -1.60005150e+00,  7.64807678e-01},
       { 1.24102325e+00,  8.20199612e-01, -1.08186625e+00,
        -1.11137489e+00, -9.72011046e-01},
       { 9.62813383e-01,  1.90135467e-01,  1.07230806e+00,
        -1.61519556e+00, -7.21553933e-01},
       { 5.31585787e-02,  4.81037218e-01, -4.74970944e-01,
         8.53916007e-01, -1.17808131e+00},
       {-1.53378966e-02,  1.15733404e+00, -7.16928745e-01,
         3.17162661e-01, -1.07557957e-01},
       { 1.08379778e+00,  1.65094779e-01,  1.03673184e+00,
        -7.63528390e-01, -1.40109563e+00},
       {-9.30253728e-01,  7.95946186e-01,  9.41141699e-02,
         8.25365631e-01,  2.96723855e-02},
       {-3.61150516e-02, -1.19637048e+00, -1.86405350e+00,
        -4.33214400e-01,  5.20845252e-01},
       {-2.72730798e-01, -7.44914065e-01,  1.28457321e+00,
        -2.17893123e+00, -4.41303356e-01},
       { 5.50793945e-01,  6.23043263e-01, -9.12888662e-01,
         1.23650463e-01,  3.91857425e-01},
       {-1.41593134e-01, -2.45498023e+00, -5.49911901e-01,
        -8.84536991e-01,  4.33368924e-01},
       { 1.11922670e+00,  1.06770889e+00,  2.84602698e-01,
         5.76157938e-01, -1.25478559e+00},
       { 1.05511083e-01,  8.12743947e-01, -9.91552927e-02,
         2.30096569e+00, -3.84773850e-01},
       { 1.12192823e+00,  1.80421663e+00, -2.05453798e-01,
         1.71930419e+00, -9.10993569e-01},
       {-6.57148436e-01,  4.58703646e-01,  6.49091660e-01,
        -5.03484767e-01,  5.34043673e-01},
       { 5.80551711e-01,  1.13757868e+00, -6.69450418e-01,
        -9.69268661e-01, -1.95699413e-03},
       {-2.13021578e-01, -8.04676766e-01,  9.43054847e-01,
         1.45036284e+00,  1.26936523e+00},
       {-2.10621693e+00, -1.00154853e+00, -3.43476410e+00,
         1.36970708e+00,  1.35007854e+00},
       { 8.81776142e-01, -6.88533863e-01,  8.33047689e-01,
        -2.15277005e+00, -1.43213616e+00},
       {-5.99706754e-02,  6.59688032e-01,  1.59065643e+00,
        -6.34034576e-01,  1.60397330e+00},
       {-3.53294296e-01, -7.27173466e-01, -2.28106495e-01,
         2.63924958e-01, -4.91099234e-01},
       { 1.98947806e+00,  1.11636942e+00, -2.73899359e-01,
        -7.65134245e-01,  3.92925226e-01},
       { 8.59522067e-02,  3.54963409e-01,  1.94700494e+00,
         4.58713146e-01, -1.38903607e-01},
       { 3.94928795e-01, -5.77989211e-01,  1.41544831e+00,
        -4.40225274e-01,  3.26974050e-01},
       { 1.34090147e-01,  1.85972285e-01,  2.34631177e+00,
         1.52221898e+00, -1.04676459e+00},
       { 2.16101554e-01, -5.90486429e-01,  1.84991228e+00,
        -1.86954400e+00,  1.96451907e+00},
       {-9.05949142e-01,  2.53286915e-01, -6.73969133e-01,
        -1.59102417e-01, -9.17224611e-01},
       { 2.59232967e-01,  9.45345497e-01,  1.64135827e-01,
        -3.07729099e-01,  2.21136912e-01},
       {-5.77721495e-01, -1.81257704e+00,  1.12608413e-01,
         1.66305994e-01, -2.52958072e-01},
       {-4.54096916e-01, -4.31075413e-01, -2.06719786e+00,
         1.45492952e-01,  8.52046241e-01},
       {-3.60659359e-01, -3.44497827e-01,  1.53839083e+00,
        -3.71694754e-02,  1.70432328e+00},
       { 1.46270533e+00,  7.33882948e-01,  4.95875712e-01,
         1.56126827e-01,  9.38077551e-01},
       {-8.88878040e-01,  7.04938472e-02, -5.99025232e-01,
         1.38912294e+00, -8.51747113e-01},
       {-1.15355875e+00,  2.65810796e-01, -3.01621299e-01,
        -9.44508103e-01, -7.21854565e-01},
       {-4.19421623e-01, -2.22261265e+00,  1.13347235e+00,
         2.15458925e-01, -7.29281066e-01},
       {-1.14039166e+00, -8.90544931e-01, -1.73150424e-01,
        -1.66788238e+00, -2.74276618e-01},
       {-3.00714312e-01,  8.80438090e-01,  7.78328980e-01,
        -1.36844656e+00,  2.36947042e-01},
       { 8.40390610e-01,  1.10005880e+00,  6.66019547e-01,
        -1.59285070e+00, -8.88849288e-02},
       {-8.37727028e-01, -4.86311468e-01,  3.67758518e-02,
         6.09349379e-01, -2.76905543e-01},
       { 9.57212298e-01, -4.84061838e-02,  7.93194016e-01,
         2.61453972e+00, -5.52540028e-01},
       {-7.14145114e-01,  6.08149326e-01,  1.29858784e+00,
         4.20327376e-01, -6.93822554e-01},
       { 4.40579314e-01,  1.07386397e+00,  1.41324546e+00,
         7.95124254e-01,  4.12462188e-01},
       {-3.52675338e-01, -3.08288382e+00, -4.05051364e-01,
        -1.38786900e+00, -6.20730501e-01},
       {-1.43219058e+00, -1.48929178e+00, -2.98647267e-01,
        -6.61694958e-01, -1.73342931e+00},
       { 8.66769180e-02, -1.56826166e-02,  7.62626494e-01,
        -7.86686758e-02, -3.23365967e-02},
       {-1.42643588e+00, -8.53682019e-02,  1.68745237e-01,
        -1.16064842e+00,  1.60106078e-04},
       {-2.81105558e-01, -2.17728537e+00,  6.95787860e-01,
        -3.44361789e-02, -3.26663344e-01},
       { 1.33906291e+00,  3.99812210e-01,  3.92013255e-01,
         5.05939754e-01,  7.72724693e-01},
       { 5.84091781e-01, -1.77225173e+00, -4.17307766e-01,
         3.53397071e-01, -2.85256903e-02},
       { 1.62331855e-02, -1.06215338e+00, -7.49286550e-01,
         1.48006947e+00, -9.43923565e-01},
       {-1.81321314e+00, -3.88028374e-01, -1.59306006e+00,
        -2.83291862e-01,  1.34377035e+00},
       { 5.18002334e-01, -7.92298711e-01,  1.24846350e-01,
        -9.89088914e-01, -9.73627713e-01},
       { 6.11040872e-02, -8.55459667e-02,  2.21172469e-01,
        -2.80992028e-01, -5.35822444e-01},
       { 1.66930589e+00,  3.94446016e-01, -3.15429798e-01,
         1.19826611e+00, -2.65860824e-01},
       {-2.23295834e+00,  8.03389181e-01, -6.78165470e-01,
         3.46924061e-01, -2.60718419e-01},
       {-5.68016197e-02, -4.67120235e-02,  2.63296789e-01,
         1.83500543e+00,  8.11938944e-01},
       {-9.34790783e-01,  6.41139636e-01,  1.60235145e-01,
         1.23418916e-02,  7.15667872e-01},
       { 9.04002236e-01, -1.49788614e+00,  9.60295238e-01,
        -1.09956542e+00, -6.84792955e-01},
       {-7.31370163e-02, -2.26495007e+00,  3.30762563e-02,
        -6.94526525e-01, -1.18614353e-01},
       { 1.43787884e-02,  6.16952846e-01,  1.39851394e+00,
         6.54879227e-01, -7.89770853e-01},
       { 6.59500278e-01,  7.65636887e-01, -6.31343772e-01,
         5.79710330e-02,  2.36182655e-02},
       {-9.76864782e-01,  1.56360393e+00,  8.47839236e-01,
        -6.03429089e-02,  1.38891298e-01},
       {-3.16976113e-01, -1.12580593e-01, -6.48887361e-03,
         8.75639104e-02,  6.32045749e-01},
       { 1.19062723e+00,  1.22913894e-02,  8.13446868e-01,
        -4.53343267e-01,  1.46020675e+00},
       {-1.84238341e+00,  1.65737273e+00, -1.57446132e+00,
         3.03878586e-01,  2.31265287e-01},
       { 1.54774942e+00, -6.24408558e-01, -4.56827971e-01,
        -3.47368011e-01, -1.36526690e+00},
       { 6.26595779e-01,  2.26337456e+00, -1.21849917e+00,
         2.39346638e-01, -4.43466266e-01},
       {-5.64088184e-01, -2.00555712e-01, -1.63953330e+00,
        -6.45228706e-01, -3.36141099e-01},
       {-3.26371114e-01, -1.18032705e+00,  2.75683915e-01,
        -7.53627214e-02,  7.16800153e-01},
       { 9.11995896e-01,  9.20258342e-01,  1.07232608e+00,
        -7.95803535e-01, -1.49518594e-02}
};

float Y[SAMPLES]=
    { 130.96679604, -131.51994566,   -6.70248592,  -57.86322548,
         66.05849387, -115.29839174,    1.17302806,  -45.34451894,
        -27.33498531,   24.18457287,  -92.36801588, -105.2829287 ,
        -90.22629664,   41.57654506,   -6.53726375, -102.17394443,
       -140.04556977,   70.10862673,   -8.18568187,  405.17435882,
        -51.95255289, -207.58875601,  -55.66754814,  -57.14348568,
         82.70513327,  182.24775293, -114.15023442,  112.08413013,
         22.98139462,  -39.46962338, -170.80831266,   -1.79651766,
         24.54271638,   45.54865706,    8.01521625,   91.05028793,
        -11.97608101, -137.82243672, -140.22917155,   33.68440237,
       -142.80258255,  173.1915306 ,  183.07259547,  248.43030308,
        -58.42016725,  -24.53461   ,  121.37224134, -271.25956725,
        -53.02602233,   43.62041252,  -41.54928504,  146.65974644,
        136.0398305 ,   63.45024636,  226.71678913,  -26.32564866,
       -131.48963831,   28.42656204,  -72.07673062, -130.28232222,
         38.21923724,  194.31919515,  -17.6744973 , -193.38282078,
        -16.6714591 , -255.63840453,  -74.89720686,   15.74866063,
        -45.69419054,  312.72769162,   27.01136593,  186.22311626,
       -210.68723504, -237.16053225,   37.23596875, -215.14743814,
        -37.97278473,  195.86396711,   31.48917184,   48.97779623,
       -266.73348098,  -35.70044696,   -9.1811169 ,  238.26360939,
       -209.51689308,  143.24428282,  -66.15629754,   21.52126955,
        -96.01948955,  118.40323564,   52.47295225,  -31.49851206,
        -22.45496402,  129.49388204, -197.85456624,   83.67679068,
         58.58223939, -181.95186816,  -40.29213663,   96.05585065};

float * getRow(float arr[SAMPLES][FEATURES],int row){
    float *data=(float*)malloc(sizeof(float)*FEATURES);
    for(int i=0;i<FEATURES;i++){
        data[i]=arr[row][i];
    }
    return data;
}

float * getCol(float arr[SAMPLES][FEATURES],int col){
    float *data=(float*)malloc(sizeof(float)*SAMPLES);
    for(int i=0;i<SAMPLES;i++){
        data[i]=arr[i][col];
    }
    return data;
}

float predict(float *X,float *coeff,float bias){
    float sum=0.0;
    for(int i=0;i<FEATURES;i++){
        sum+=X[i]*coeff[i];
    }
    return sum+bias;
}

float summation(float * data){
    float sum=0;
    for(int i=0;i<SAMPLES;i++){
        sum+=data[i];
    }
    return sum;
}

void display(float *data,int count){
    for(int i=0;i<count;i++){
        printf("%f \t",data[i]);
    }
    printf("\n ----------------------------------------------------- \n");
}

float mse(float * Y, float * Y_pred){
    float sum=0;
    for(int i=0;i<SAMPLES;i++){
        sum+=pow(Y[i]-Y_pred[i],2);
    }
    printf("The mse is : %f",sum/SAMPLES);
    return (sum/SAMPLES);
}

void LinearRegression(float lr,int iter){
    // First we define a coeff array which is equal to the number of features in the data
    float *coeff=(float*)malloc(sizeof(float)*FEATURES);
    // We initialize the coeff values to 0
    for(int i=0;i<FEATURES;i++){
        coeff[i]=0;
    }
    // Next we define the bias of the data
    float bias=0;
    // We define an array to hold the predicted Y values
    float *y_pred=(float*)malloc(sizeof(float)*SAMPLES);
    // We define an array to hold the error values
    float *error=(float*)malloc(sizeof(float)*SAMPLES);
    // We define an array to hold the derivatives of the coeff
    float *dw=(float*)malloc(sizeof(float)*FEATURES);
    // We define an array to hold the predicted Y values
    float db;
    // We define an array to hold the predicted Y values
    float *temp1=(float*)malloc(sizeof(float)*FEATURES);
    float *temp2=(float*)malloc(sizeof(float)*SAMPLES);
    for(int a=0;a<=iter;a++){
        for(int b=0;b<SAMPLES;b++){
            temp1=getRow(X,b);
            y_pred[b]=predict(temp1,coeff,bias);
            error[b]=Y[b]-y_pred[b];
        }

        for(int c=0;c<FEATURES;c++){
            temp2=getCol(X,c);
            float sum=0;
            for(int d=0;d<SAMPLES;d++){
                sum+=error[d]*temp2[d];
            }
            dw[c]=sum/SAMPLES;
            coeff[c]=coeff[c]+lr*dw[c];
        }

        db=summation(error)/SAMPLES;
        bias=bias+lr*db;
    }
    // display(y_pred,SAMPLES);
    // display(error,SAMPLES);
    // display(coeff,FEATURES);
    // printf("The bias is %f \n",bias);
    mse(Y,y_pred);
}

int main(){
    LinearRegression(0.01,1000);
}