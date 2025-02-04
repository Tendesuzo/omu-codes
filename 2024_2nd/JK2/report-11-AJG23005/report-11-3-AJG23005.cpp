//AJG23005 中 天花
#include <iostream>
#include <cmath>
#include "ex2image.h"

int square(int x) {
    return x * x;
}

int main(int argc, const char * argv[])
{
    ex2image img;
    std::string s_file = "block.pgm";
    if( !img.load( s_file.c_str() ) ){
	  std::cerr << "cannot open the file!:" <<  s_file << std::endl;
	  exit( -1 );
	}

	//保存用の画像のバッファ
    ex2image three( img );

    double max_value = 0.0;
    double min_value = 1e10;

	//画像を反転させる
	int w_three = three.img_width();
	int h_three = three.img_height();
	for( int j=1; j<h_three-1; j++ ){
	  for( int i=1; i<w_three-1; i++ ){
		double x = (-1) * img(i-1, j-1, 0) + img(i+1, j-1, 0)
                        - 2 * img(i-1, j, 0) + 2 * img(i+1, j, 0)
                        - img(i-1, j+1, 0) + img(i+1, j+1, 0);
            double y = img(i-1, j-1, 0) + 2 * img(i, j-1, 0) + img(i+1, j-1, 0)
                        - img(i-1, j+1, 0) - 2 * img(i, j+1, 0) - img(i+1, j+1, 0);
            double gradientMagnitude = sqrt(square(x) + square(y));

            // 勾配の大きさを保存
            three(i, j, 0) = gradientMagnitude;

            // 最大値と最小値を更新
            if (gradientMagnitude > max_value) max_value = gradientMagnitude;
            if (gradientMagnitude < min_value) min_value = gradientMagnitude;
	  }
	}

    for (int j = 1; j < h_three - 1; j++) {
        for (int i = 1; i < w_three - 1; i++) {
            double result = (three(i, j, 0) - min_value) / (max_value - min_value) * 255.0;
            three(i, j, 0) = static_cast<unsigned char>(result);
        }
    }


    if( !three.write( "mag-AJG23005.pgm" ) ){
	  std::cerr << "cannot write the file!: mag-AJG23005.pgm" << std::endl;
	  exit( -1 );
	}

    return 0;
}
