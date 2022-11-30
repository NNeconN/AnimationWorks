xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 76;
 1.12053;1.79508;-1.24763;,
 0.87522;1.98019;-1.32496;,
 0.71494;2.82741;-0.46658;,
 1.00400;2.73652;-0.04917;,
 1.12053;1.79508;-1.24763;,
 0.00000;1.32430;-1.58447;,
 0.00000;1.65925;-1.59773;,
 0.87522;1.98019;-1.32496;,
 0.71494;2.82741;-0.46658;,
 -0.71494;2.82741;-0.46658;,
 -1.00400;2.73652;-0.04917;,
 1.00400;2.73652;-0.04917;,
 1.00400;2.73652;-0.04917;,
 2.10912;2.27100;0.23202;,
 2.05070;1.37637;-1.19049;,
 1.12053;1.79508;-1.24763;,
 1.12053;1.79508;-1.24763;,
 2.05070;1.37637;-1.19049;,
 0.00000;0.69739;-1.67471;,
 0.00000;1.32430;-1.58447;,
 1.49494;0.11826;-0.50717;,
 0.00000;-0.04394;-1.20618;,
 2.10912;2.27100;0.23202;,
 1.32014;0.69758;0.83796;,
 1.49494;0.11826;-0.50717;,
 2.05070;1.37637;-1.19049;,
 1.32014;0.69758;0.83796;,
 0.81871;0.00345;0.95755;,
 1.12674;-0.26930;-0.24352;,
 1.49494;0.11826;-0.50717;,
 1.12674;-0.26930;-0.24352;,
 0.02387;-0.37712;-0.76181;,
 1.00400;2.73652;-0.04917;,
 0.70383;2.31956;0.61671;,
 2.10912;2.27100;0.23202;,
 -2.10912;2.27100;0.23202;,
 -0.70383;2.31956;0.61671;,
 -1.00400;2.73652;-0.04917;,
 1.32014;0.69758;0.83796;,
 -1.32014;0.69758;0.83796;,
 -0.81871;0.00345;0.95755;,
 0.81871;0.00345;0.95755;,
 1.32014;0.69758;0.83796;,
 -1.32014;0.69758;0.83796;,
 -0.87522;1.98019;-1.32496;,
 -0.71494;2.82741;-0.46658;,
 0.00000;1.65925;-1.59773;,
 0.71494;2.82741;-0.46658;,
 0.87522;1.98019;-1.32496;,
 0.02387;-0.37712;-0.76181;,
 -0.81871;0.00345;0.95755;,
 -1.12674;-0.26930;-0.24352;,
 1.12674;-0.26930;-0.24352;,
 0.81871;0.00345;0.95755;,
 -1.12053;1.79508;-1.24763;,
 -1.00400;2.73652;-0.04917;,
 -0.71494;2.82741;-0.46658;,
 -0.87522;1.98019;-1.32496;,
 -1.12053;1.79508;-1.24763;,
 -0.87522;1.98019;-1.32496;,
 -1.00400;2.73652;-0.04917;,
 -1.12053;1.79508;-1.24763;,
 -2.05070;1.37637;-1.19049;,
 -2.10912;2.27100;0.23202;,
 -1.12053;1.79508;-1.24763;,
 -2.05070;1.37637;-1.19049;,
 -1.49494;0.11826;-0.50717;,
 -2.10912;2.27100;0.23202;,
 -2.05070;1.37637;-1.19049;,
 -1.49494;0.11826;-0.50717;,
 -1.32014;0.69758;0.83796;,
 -1.32014;0.69758;0.83796;,
 -1.49494;0.11826;-0.50717;,
 -1.12674;-0.26930;-0.24352;,
 -0.81871;0.00345;0.95755;,
 -1.12674;-0.26930;-0.24352;;
 
 30;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;17,20,21,18;,
 4;22,23,24,25;,
 4;26,27,28,29;,
 4;30,31,21,20;,
 3;32,33,34;,
 3;35,36,37;,
 3;33,38,34;,
 3;35,39,36;,
 4;32,37,36,33;,
 4;33,36,39,38;,
 4;40,41,42,43;,
 3;44,45,46;,
 3;46,47,48;,
 3;46,45,47;,
 3;49,50,51;,
 3;52,53,49;,
 3;53,50,49;,
 4;54,55,56,57;,
 4;58,59,6,5;,
 4;60,61,62,63;,
 4;64,19,18,65;,
 4;65,18,21,66;,
 4;67,68,69,70;,
 4;71,72,73,74;,
 4;75,66,21,31;;
 
 MeshMaterialList {
  1;
  30;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.250000;0.250000;0.250000;;
   TextureFilename {
    "assets\\model\\Char\\E2\\e2_bodytex.bmp";
   }
  }
 }
 MeshNormals {
  40;
  0.438622;0.416109;-0.796533;,
  0.356546;0.486501;-0.797616;,
  0.226658;0.712882;-0.663645;,
  0.549670;0.682106;-0.482281;,
  -0.356546;0.486501;-0.797617;,
  -0.183632;0.859966;-0.476170;,
  -0.063376;0.890556;0.450437;,
  0.000000;0.454786;-0.890601;,
  0.000000;0.079298;-0.996851;,
  -0.239248;0.542057;0.805565;,
  0.410554;0.751728;-0.516091;,
  0.326831;0.502246;-0.800581;,
  0.000000;-0.198200;-0.980162;,
  0.002749;-0.689628;-0.724159;,
  0.371341;-0.637618;-0.674944;,
  -0.088915;0.179326;0.979764;,
  0.860922;-0.428138;0.274793;,
  0.440791;-0.843605;0.306648;,
  0.289313;-0.914988;0.281237;,
  -0.446241;-0.894851;-0.010495;,
  0.000000;0.169794;0.985480;,
  0.002212;-0.993780;-0.111341;,
  0.122866;0.546298;0.828530;,
  -0.122866;0.546298;0.828530;,
  -0.438622;0.416109;-0.796533;,
  -0.326831;0.502246;-0.800581;,
  -0.366670;-0.644293;-0.671148;,
  0.000000;0.977101;0.212778;,
  0.063376;0.890556;0.450437;,
  0.387798;-0.525556;-0.757234;,
  0.918307;-0.328589;0.220775;,
  0.347606;-0.737181;-0.579425;,
  0.239248;0.542057;0.805565;,
  0.088915;0.179326;0.979764;,
  -0.289411;-0.914952;0.281254;,
  -0.549670;0.682106;-0.482281;,
  -0.410554;0.751728;-0.516091;,
  -0.387798;-0.525556;-0.757234;,
  -0.918307;-0.328589;0.220775;,
  -0.860922;-0.428138;0.274793;;
  30;
  4;0,1,2,3;,
  4;0,8,7,1;,
  4;27,5,6,28;,
  4;3,10,11,0;,
  4;0,11,12,8;,
  4;29,14,13,12;,
  4;30,16,16,30;,
  4;16,18,17,16;,
  4;31,21,13,14;,
  3;28,22,32;,
  3;9,23,6;,
  3;22,33,32;,
  3;9,15,23;,
  4;28,6,23,22;,
  4;22,23,15,33;,
  4;20,20,33,15;,
  3;4,5,7;,
  3;7,2,1;,
  3;7,5,2;,
  3;21,34,19;,
  3;17,18,21;,
  3;18,34,21;,
  4;24,35,5,4;,
  4;24,4,7,8;,
  4;35,24,25,36;,
  4;24,8,12,25;,
  4;37,12,13,26;,
  4;38,38,39,39;,
  4;39,39,19,34;,
  4;19,26,13,21;;
 }
 MeshTextureCoords {
  76;
  -0.445420;0.178460;
  -0.401210;0.191280;
  -0.388930;0.398690;
  -0.452380;0.442240;
  -0.469310;0.332090;
  -0.405130;0.141580;
  -0.378840;0.159150;
  -0.432170;0.306450;
  -0.397700;0.187520;
  -0.397900;0.433030;
  -0.460410;0.480720;
  -0.460130;0.135950;
  -0.454580;0.121180;
  -0.518280;0.434240;
  -0.915770;0.335060;
  -0.828590;0.087600;
  -0.704930;0.004890;
  -0.471390;0.095670;
  -0.993820;0.197570;
  -0.991780;0.072450;
  -0.598540;0.471970;
  -0.985590;0.425250;
  0.018550;0.052280;
  -0.009740;0.529630;
  -0.472090;0.511670;
  -0.511420;0.117910;
  -0.039160;0.502550;
  -0.026990;0.723110;
  -0.343780;0.714680;
  -0.401600;0.575600;
  -0.686020;0.597170;
  -0.975080;0.567200;
  -0.517180;0.173660;
  -0.509730;0.246670;
  -0.675840;0.274650;
  -0.219910;0.003600;
  -0.357580;0.156220;
  -0.300150;0.044630;
  -0.731510;0.270830;
  -0.446140;0.101180;
  0.063680;0.655920;
  0.403550;0.655920;
  0.507630;0.466370;
  -0.040400;0.466370;
  -0.106920;0.485140;
  -0.286530;0.460900;
  -0.046880;0.333180;
  -0.290420;0.216110;
  -0.111690;0.185480;
  -0.501270;0.564540;
  -0.650160;0.825410;
  -0.690740;0.623260;
  -0.317420;0.634380;
  -0.378900;0.833480;
  -0.445420;0.178460;
  -0.452380;0.442240;
  -0.388930;0.398690;
  -0.401210;0.191280;
  -0.469310;0.332090;
  -0.432170;0.306450;
  -0.454580;0.121180;
  -0.828590;0.087600;
  -0.915770;0.335060;
  -0.518280;0.434240;
  -0.704930;0.004890;
  -0.471390;0.095670;
  -0.598540;0.471970;
  0.018550;0.052280;
  -0.511420;0.117910;
  -0.472090;0.511670;
  -0.009740;0.529630;
  -0.039160;0.502550;
  -0.401600;0.575600;
  -0.343780;0.714680;
  -0.026990;0.723110;
  -0.686020;0.597170;;
 }
}