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
 19;
 0.00000;0.60587;-1.00842;,
 0.93719;0.67239;-0.36160;,
 0.33845;-0.28712;-0.70496;,
 -0.33845;-0.28712;-0.70496;,
 -0.93719;0.67239;-0.36160;,
 0.58764;0.72986;0.71173;,
 -0.58764;0.72986;0.71173;,
 0.00000;-0.24366;0.65848;,
 -1.41804;-0.18538;-0.52817;,
 1.41804;-0.18538;-0.52817;,
 -1.19044;-0.16987;0.26442;,
 1.19044;-0.16987;0.26442;,
 -0.64369;1.61949;-0.38945;,
 0.00000;1.43418;-0.89231;,
 0.64369;1.61949;-0.38945;,
 0.53513;1.55196;0.12079;,
 -0.53513;1.55196;0.12079;,
 0.87835;-1.00482;-0.32018;,
 -0.87835;-1.00482;-0.32018;;
 
 24;
 3;0,1,2;,
 3;3,4,0;,
 3;2,3,0;,
 3;5,6,7;,
 3;2,7,3;,
 3;3,8,4;,
 3;1,9,2;,
 3;6,10,7;,
 3;7,11,5;,
 4;4,12,13,0;,
 4;0,13,14,1;,
 4;14,15,5,1;,
 4;4,6,16,12;,
 4;6,5,15,16;,
 4;8,10,6,4;,
 4;1,5,11,9;,
 3;9,17,2;,
 3;3,18,8;,
 3;11,17,9;,
 3;8,18,10;,
 3;11,7,17;,
 3;18,7,10;,
 3;2,17,7;,
 3;7,18,3;;
 
 MeshMaterialList {
  1;
  24;
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
    "assets\\model\\Char\\E2\\e2_othertex.bmp";
   }
  }
 }
 MeshNormals {
  32;
  0.165808;-0.032820;-0.985612;,
  0.438221;0.114803;-0.891506;,
  0.234504;-0.126575;-0.963840;,
  -0.438221;0.114803;-0.891506;,
  -0.234504;-0.126575;-0.963840;,
  0.115340;0.103878;0.987880;,
  -0.115340;0.103878;0.987880;,
  0.000000;-0.381979;0.924171;,
  -0.165936;-0.049317;-0.984902;,
  0.165936;-0.049317;-0.984902;,
  -0.524737;-0.492760;0.694146;,
  0.524737;-0.492760;0.694146;,
  -0.569414;0.135686;-0.810775;,
  0.569414;0.135686;-0.810775;,
  0.924060;0.279256;0.261016;,
  -0.924060;0.279256;0.261016;,
  0.183530;-0.353667;-0.917189;,
  -0.183530;-0.353667;-0.917189;,
  -0.569908;-0.062430;-0.819334;,
  -0.410567;-0.908908;-0.072945;,
  0.410567;-0.908908;-0.072945;,
  0.896291;0.362595;0.255319;,
  -0.896291;0.362595;0.255319;,
  0.000000;0.583675;0.811988;,
  -0.959375;-0.025122;0.281012;,
  -0.861576;0.443124;0.247644;,
  0.861576;0.443124;0.247644;,
  0.959375;-0.025122;0.281012;,
  0.602632;-0.596464;0.530156;,
  -0.602632;-0.596464;0.530156;,
  -0.744048;-0.647673;-0.164050;,
  0.744048;-0.647673;-0.164050;;
  24;
  3;0,1,2;,
  3;4,3,18;,
  3;2,4,0;,
  3;5,6,7;,
  3;19,19,20;,
  3;4,8,3;,
  3;1,9,2;,
  3;6,10,7;,
  3;7,11,5;,
  4;3,12,12,0;,
  4;0,13,13,1;,
  4;14,14,21,21;,
  4;22,22,15,15;,
  4;6,5,23,23;,
  4;24,25,22,22;,
  4;21,21,26,27;,
  3;9,16,2;,
  3;4,17,8;,
  3;11,28,27;,
  3;24,29,10;,
  3;11,7,28;,
  3;29,7,10;,
  3;19,30,19;,
  3;31,31,20;;
 }
 MeshTextureCoords {
  19;
  1.191070;0.641530;
  1.881570;0.634890;
  1.440420;0.730570;
  0.941710;0.730570;
  0.500560;0.634890;
  1.624020;0.629160;
  0.758110;0.629160;
  1.191070;0.726230;
  0.146290;0.720420;
  2.235840;0.720420;
  0.313970;0.718880;
  2.068160;0.718880;
  0.716810;0.540460;
  1.191070;0.558930;
  1.665320;0.540460;
  1.585330;0.547190;
  0.796800;0.547190;
  1.838210;0.802130;
  0.543920;0.802130;;
 }
}