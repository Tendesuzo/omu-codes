//AJG23005 中 天花
#include <iostream>
#include "ex2image.h"

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
	ex2image five( img );
	ex2image seven( img );

	//画像を反転させる
	int w_three = three.img_width();
	int h_three = three.img_height();
	for( int j=1; j<h_three-1; j++ ){
	  for( int i=1; i<w_three-1; i++ ){
		three( i, j, 0 ) = (1.0)/(9.0) * (img(i-1, j-1, 0) + img(i, j-1, 0) + img(i+1, j-1, 0) + img(i-1, j, 0) + img(i, j, 0) + img(i+1, j, 0) + img(i-1, j+1, 0) + img(i, j+1, 0) + img(i+1, j+1, 0));
	  }
	}

	int w_five = five.img_width();
	int h_five = five.img_height();
	for( int j=2; j<h_five-2; j++ ){
	  for( int i=2; i<w_five-2; i++ ){
		five( i, j, 0 ) = (1.0)/(25.0) * (img(i-2, j-2, 0) + img(i-1, j-2, 0) + img(i, j-2, 0) + img(i+1, j-2, 0) + img(i+2, j-2, 0) + img(i-2, j-1, 0) + img(i-1, j-1, 0) + img(i, j-1, 0) + img(i+1, j-1, 0) + img(i+2, j-1, 0) + img(i-2, j, 0) + img(i-1, j, 0) + img(i, j, 0) + img(i+1, j, 0) + img(i+2, j, 0) + img(i-2, j+1, 0) + img(i-1, j+1, 0) + img(i, j+1, 0) + img(i+1, j+1, 0) + img(i+2, j+1, 0) + img(i-2, j+2, 0) + img(i-1, j+2, 0) + img(i, j+2, 0) + img(i+1, j+2, 0) + img(i+2, j+2, 0));
	  }
	}

	int w_seven = seven.img_width();
	int h_seven = seven.img_height();
	for( int j=3; j<h_seven-3; j++ ){
	  for( int i=3; i<w_seven-3; i++ ){
		seven( i, j, 0 ) = (1.0)/(49.0) * (img(i-3, j-3, 0) + img(i-2, j-3, 0) + img(i-1, j-3, 0) + img(i, j-3, 0) + img(i+1, j-3, 0) + img(i+2, j-3, 0) + img(i+3, j-3, 0) + img(i-3, j-2, 0) + img(i-2, j-2, 0) + img(i-1, j-2, 0) + img(i, j-2, 0) + img(i+1, j-2, 0) + img(i+2, j-2, 0) + img(i+3, j-2, 0) + img(i-3, j-1, 0) + img(i-2, j-1, 0) + img(i-1, j-1, 0) + img(i, j-1, 0) + img(i+1, j-1, 0) + img(i+2, j-1, 0) + img(i+3, j-1, 0) + img(i-3, j, 0) + img(i-2, j, 0) + img(i-1, j, 0) + img(i, j, 0) + img(i+1, j, 0) + img(i+2, j, 0) + img(i+3, j, 0) + img(i-3, j+1, 0) + img(i-2, j+1, 0) + img(i-1, j+1, 0) + img(i, j+1, 0) + img(i+1, j+1, 0) + img(i+2, j+1, 0) + img(i+3, j+1, 0) + img(i-3, j+2, 0) + img(i-2, j+2, 0) + img(i-1, j+2, 0) + img(i, j+2, 0) + img(i+1, j+2, 0) + img(i+2, j+2, 0) + img(i+3, j+2, 0) + img(i-3, j+3, 0) + img(i-2, j+3, 0) + img(i-1, j+3, 0) + img(i, j+3, 0) + img(i+1, j+3, 0) + img(i+2, j+3, 0) + img(i+3, j+3, 0));
	  }
	}

    if( !three.write( "average-AJG23005-3.pgm" ) ){
	  std::cerr << "cannot write the file!: average-AJG23005-3.pgm" << std::endl;
	  exit( -1 );
	}

	if( !five.write( "average-AJG23005-5.pgm" ) ){
	  std::cerr << "cannot write the file!: average-AJG23005-5.pgm" << std::endl;
	  exit( -1 );
	}

	if( !seven.write( "average-AJG23005-7.pgm" ) ){
	  std::cerr << "cannot write the file!: average-AJG23005-7.pgm" << std::endl;
	  exit( -1 );
	}

    return 0;
}
