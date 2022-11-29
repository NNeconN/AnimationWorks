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
 144;
 -737.81561;737.81567;-737.81567;,
 -867.77185;437.65881;-867.77185;,
 -472.87274;472.87274;-1106.72351;,
 -437.65881;867.77185;-867.77185;,
 -931.91150;0.00000;-931.91144;,
 -508.08667;0.00000;-1187.21240;,
 0.00000;-0.00001;-1272.73193;,
 0.00000;508.08667;-1187.21240;,
 0.00000;931.91150;-931.91144;,
 -737.81561;-737.81567;-737.81567;,
 -437.65881;-867.77185;-867.77185;,
 -472.87274;-472.87274;-1106.72351;,
 -867.77185;-437.65881;-867.77185;,
 0.00000;-931.91150;-931.91144;,
 0.00000;-508.08667;-1187.21240;,
 737.81561;-737.81567;-737.81567;,
 867.77185;-437.65881;-867.77185;,
 472.87274;-472.87274;-1106.72351;,
 437.65881;-867.77185;-867.77185;,
 931.91150;0.00000;-931.91144;,
 508.08667;0.00000;-1187.21240;,
 737.81561;737.81567;-737.81567;,
 437.65881;867.77185;-867.77185;,
 472.87274;472.87274;-1106.72351;,
 867.77185;437.65881;-867.77185;,
 737.81561;737.81567;-737.81567;,
 867.77185;437.65881;-867.77185;,
 1106.72351;472.87274;-472.87274;,
 867.77185;867.77185;-437.65881;,
 931.91150;0.00000;-931.91144;,
 1187.21240;0.00000;-508.08667;,
 1272.73193;-0.00001;0.00000;,
 1187.21240;508.08667;0.00000;,
 931.91144;931.91150;0.00000;,
 737.81561;-737.81567;-737.81567;,
 867.77185;-867.77185;-437.65881;,
 1106.72351;-472.87274;-472.87274;,
 867.77185;-437.65881;-867.77185;,
 931.91144;-931.91150;-0.00000;,
 1187.21240;-508.08667;-0.00000;,
 737.81567;-737.81567;737.81561;,
 867.77185;-437.65881;867.77185;,
 1106.72351;-472.87274;472.87274;,
 867.77185;-867.77185;437.65881;,
 931.91144;0.00000;931.91150;,
 1187.21240;0.00000;508.08667;,
 737.81567;737.81567;737.81561;,
 867.77185;867.77185;437.65881;,
 1106.72351;472.87274;472.87274;,
 867.77185;437.65881;867.77185;,
 737.81567;737.81567;737.81561;,
 867.77185;437.65881;867.77185;,
 472.87274;472.87274;1106.72351;,
 437.65881;867.77185;867.77185;,
 931.91144;0.00000;931.91150;,
 508.08667;0.00000;1187.21240;,
 -0.00000;-0.00001;1272.73193;,
 0.00000;508.08667;1187.21240;,
 0.00000;931.91150;931.91144;,
 737.81567;-737.81567;737.81561;,
 437.65881;-867.77185;867.77185;,
 472.87274;-472.87274;1106.72351;,
 867.77185;-437.65881;867.77185;,
 0.00000;-931.91150;931.91144;,
 0.00000;-508.08667;1187.21240;,
 -737.81561;-737.81567;737.81567;,
 -867.77185;-437.65881;867.77185;,
 -472.87274;-472.87274;1106.72351;,
 -437.65881;-867.77185;867.77185;,
 -931.91150;0.00000;931.91144;,
 -508.08667;0.00000;1187.21240;,
 -737.81561;737.81567;737.81567;,
 -437.65881;867.77185;867.77185;,
 -472.87274;472.87274;1106.72351;,
 -867.77185;437.65881;867.77185;,
 -737.81561;737.81567;737.81567;,
 -867.77185;437.65881;867.77185;,
 -1106.72351;472.87274;472.87274;,
 -867.77185;867.77185;437.65881;,
 -931.91150;0.00000;931.91144;,
 -1187.21240;0.00000;508.08667;,
 -1272.73193;-0.00001;-0.00000;,
 -1187.21240;508.08667;0.00000;,
 -931.91144;931.91150;0.00000;,
 -737.81561;-737.81567;737.81567;,
 -867.77185;-867.77185;437.65881;,
 -1106.72351;-472.87274;472.87274;,
 -867.77185;-437.65881;867.77185;,
 -931.91144;-931.91150;0.00000;,
 -1187.21240;-508.08667;0.00000;,
 -737.81561;-737.81567;-737.81567;,
 -867.77185;-437.65881;-867.77185;,
 -1106.72351;-472.87274;-472.87274;,
 -867.77185;-867.77185;-437.65881;,
 -931.91150;0.00000;-931.91144;,
 -1187.21240;0.00000;-508.08667;,
 -737.81561;737.81567;-737.81567;,
 -867.77185;867.77185;-437.65881;,
 -1106.72351;472.87274;-472.87274;,
 -867.77185;437.65881;-867.77185;,
 -867.77185;867.77185;437.65881;,
 -472.87274;1106.72351;472.87274;,
 -437.65881;867.77185;867.77185;,
 -931.91144;931.91150;0.00000;,
 -508.08667;1187.21240;0.00000;,
 0.00000;1272.73193;-0.00001;,
 0.00000;1187.21240;508.08667;,
 -737.81561;737.81567;-737.81567;,
 -437.65881;867.77185;-867.77185;,
 -472.87274;1106.72351;-472.87274;,
 -867.77185;867.77185;-437.65881;,
 0.00000;931.91150;-931.91144;,
 0.00000;1187.21240;-508.08667;,
 737.81561;737.81567;-737.81567;,
 867.77185;867.77185;-437.65881;,
 472.87274;1106.72351;-472.87274;,
 437.65881;867.77185;-867.77185;,
 931.91144;931.91150;0.00000;,
 508.08667;1187.21240;0.00000;,
 437.65881;867.77185;867.77185;,
 472.87274;1106.72351;472.87274;,
 867.77185;867.77185;437.65881;,
 -737.81561;-737.81567;-737.81567;,
 -867.77185;-867.77185;-437.65881;,
 -472.87274;-1106.72351;-472.87274;,
 -437.65881;-867.77185;-867.77185;,
 -931.91144;-931.91150;0.00000;,
 -508.08667;-1187.21240;0.00000;,
 0.00000;-1272.73193;0.00001;,
 0.00000;-1187.21240;-508.08667;,
 0.00000;-931.91150;-931.91144;,
 -437.65881;-867.77185;867.77185;,
 -472.87274;-1106.72351;472.87274;,
 -867.77185;-867.77185;437.65881;,
 0.00000;-1187.21240;508.08667;,
 867.77185;-867.77185;437.65881;,
 472.87274;-1106.72351;472.87274;,
 437.65881;-867.77185;867.77185;,
 931.91144;-931.91150;-0.00000;,
 508.08667;-1187.21240;-0.00000;,
 737.81561;-737.81567;-737.81567;,
 437.65881;-867.77185;-867.77185;,
 472.87274;-1106.72351;-472.87274;,
 867.77185;-867.77185;-437.65881;;
 
 96;
 4;0,1,2,3;,
 4;4,5,2,1;,
 4;6,7,2,5;,
 4;8,3,2,7;,
 4;9,10,11,12;,
 4;13,14,11,10;,
 4;6,5,11,14;,
 4;4,12,11,5;,
 4;15,16,17,18;,
 4;19,20,17,16;,
 4;6,14,17,20;,
 4;13,18,17,14;,
 4;21,22,23,24;,
 4;8,7,23,22;,
 4;6,20,23,7;,
 4;19,24,23,20;,
 4;25,26,27,28;,
 4;29,30,27,26;,
 4;31,32,27,30;,
 4;33,28,27,32;,
 4;34,35,36,37;,
 4;38,39,36,35;,
 4;31,30,36,39;,
 4;29,37,36,30;,
 4;40,41,42,43;,
 4;44,45,42,41;,
 4;31,39,42,45;,
 4;38,43,42,39;,
 4;46,47,48,49;,
 4;33,32,48,47;,
 4;31,45,48,32;,
 4;44,49,48,45;,
 4;50,51,52,53;,
 4;54,55,52,51;,
 4;56,57,52,55;,
 4;58,53,52,57;,
 4;59,60,61,62;,
 4;63,64,61,60;,
 4;56,55,61,64;,
 4;54,62,61,55;,
 4;65,66,67,68;,
 4;69,70,67,66;,
 4;56,64,67,70;,
 4;63,68,67,64;,
 4;71,72,73,74;,
 4;58,57,73,72;,
 4;56,70,73,57;,
 4;69,74,73,70;,
 4;75,76,77,78;,
 4;79,80,77,76;,
 4;81,82,77,80;,
 4;83,78,77,82;,
 4;84,85,86,87;,
 4;88,89,86,85;,
 4;81,80,86,89;,
 4;79,87,86,80;,
 4;90,91,92,93;,
 4;94,95,92,91;,
 4;81,89,92,95;,
 4;88,93,92,89;,
 4;96,97,98,99;,
 4;83,82,98,97;,
 4;81,95,98,82;,
 4;94,99,98,95;,
 4;75,100,101,102;,
 4;103,104,101,100;,
 4;105,106,101,104;,
 4;58,102,101,106;,
 4;107,108,109,110;,
 4;111,112,109,108;,
 4;105,104,109,112;,
 4;103,110,109,104;,
 4;113,114,115,116;,
 4;117,118,115,114;,
 4;105,112,115,118;,
 4;111,116,115,112;,
 4;46,119,120,121;,
 4;58,106,120,119;,
 4;105,118,120,106;,
 4;117,121,120,118;,
 4;122,123,124,125;,
 4;126,127,124,123;,
 4;128,129,124,127;,
 4;130,125,124,129;,
 4;84,131,132,133;,
 4;63,134,132,131;,
 4;128,127,132,134;,
 4;126,133,132,127;,
 4;40,135,136,137;,
 4;138,139,136,135;,
 4;128,134,136,139;,
 4;63,137,136,134;,
 4;140,141,142,143;,
 4;130,129,142,141;,
 4;128,139,142,129;,
 4;138,143,142,139;;
 
 MeshMaterialList {
  6;
  96;
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
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
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "sky_x1.tga";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "sky_x2.tga";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "sky_y1.tga";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "sky_z1.tga";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "sky_z2.tga";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "sky_y2.tga";
   }
  }
 }
 MeshNormals {
  98;
  0.353225;-0.353225;0.866294;,
  0.353225;0.353225;0.866294;,
  -0.353225;0.353225;0.866294;,
  -0.353225;-0.353225;0.866294;,
  -0.866294;-0.353225;0.353225;,
  -0.866294;0.353225;0.353225;,
  -0.866294;0.353225;-0.353225;,
  -0.866294;-0.353225;-0.353225;,
  -0.353225;-0.353225;-0.866294;,
  -0.353225;0.353225;-0.866294;,
  0.353225;0.353225;-0.866294;,
  0.353225;-0.353225;-0.866294;,
  0.866294;-0.353225;-0.353225;,
  0.866294;0.353225;-0.353225;,
  0.866294;0.353225;0.353225;,
  0.866294;-0.353225;0.353225;,
  0.353225;-0.866294;-0.353225;,
  0.353225;-0.866294;0.353225;,
  -0.353225;-0.866294;0.353225;,
  -0.353225;-0.866294;-0.353225;,
  0.353225;0.866294;0.353225;,
  0.353225;0.866294;-0.353225;,
  -0.353225;0.866294;-0.353225;,
  -0.353225;0.866294;0.353225;,
  0.661299;-0.354071;0.661299;,
  0.353812;0.000000;0.935316;,
  0.000000;-0.353812;0.935316;,
  0.354071;-0.661299;0.661299;,
  0.354071;0.661299;0.661299;,
  0.000000;0.353812;0.935316;,
  0.661299;0.354071;0.661299;,
  -0.661299;0.354071;0.661299;,
  -0.353812;0.000000;0.935316;,
  -0.354071;0.661299;0.661299;,
  -0.354071;-0.661299;0.661299;,
  -0.661299;-0.354071;0.661299;,
  -0.935316;0.000000;0.353812;,
  -0.935316;-0.353812;0.000000;,
  -0.661299;-0.661299;0.354071;,
  -0.661299;0.661299;0.354071;,
  -0.935316;0.353812;0.000000;,
  -0.661299;0.354071;-0.661299;,
  -0.935316;0.000000;-0.353812;,
  -0.661299;0.661299;-0.354071;,
  -0.661299;-0.661299;-0.354071;,
  -0.661299;-0.354071;-0.661299;,
  -0.353812;0.000000;-0.935316;,
  0.000000;-0.353812;-0.935316;,
  -0.354071;-0.661299;-0.661299;,
  -0.354071;0.661299;-0.661299;,
  0.000000;0.353812;-0.935316;,
  0.661299;0.354071;-0.661299;,
  0.353812;0.000000;-0.935316;,
  0.354071;0.661299;-0.661299;,
  0.354071;-0.661299;-0.661299;,
  0.661299;-0.354071;-0.661299;,
  0.935316;0.000000;-0.353812;,
  0.935316;-0.353812;-0.000000;,
  0.661299;-0.661299;-0.354071;,
  0.661299;0.661299;-0.354071;,
  0.935316;0.353812;0.000000;,
  0.935316;0.000000;0.353812;,
  0.661299;0.661299;0.354071;,
  0.661299;-0.661299;0.354071;,
  0.353812;-0.935316;0.000000;,
  -0.000000;-0.935316;-0.353812;,
  0.000000;-0.935316;0.353812;,
  -0.353812;-0.935316;0.000000;,
  0.353812;0.935316;-0.000000;,
  -0.000000;0.935316;0.353812;,
  0.000000;0.935316;-0.353812;,
  -0.353812;0.935316;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;1.000000;-0.000000;,
  0.707107;0.000000;0.707107;,
  0.000000;0.707107;0.707107;,
  -0.707107;0.000000;0.707107;,
  0.000000;-0.707107;0.707107;,
  -0.707107;0.707107;0.000000;,
  -0.707107;0.000000;-0.707107;,
  -0.707107;-0.707107;0.000000;,
  0.000000;0.707107;-0.707107;,
  0.707107;0.000000;-0.707107;,
  0.000000;-0.707107;-0.707107;,
  0.707107;0.707107;0.000000;,
  0.707107;-0.707107;-0.000000;,
  0.577350;-0.577350;0.577350;,
  0.577350;0.577350;0.577350;,
  -0.577350;-0.577350;0.577350;,
  -0.577350;0.577350;0.577350;,
  -0.577350;-0.577350;-0.577350;,
  -0.577350;0.577350;-0.577350;,
  0.577350;-0.577350;-0.577350;,
  0.577350;0.577350;-0.577350;;
  96;
  4;90,24,0,27;,
  4;78,25,0,24;,
  4;72,26,0,25;,
  4;81,27,0,26;,
  4;91,28,1,30;,
  4;79,29,1,28;,
  4;72,25,1,29;,
  4;78,30,1,25;,
  4;93,31,2,33;,
  4;80,32,2,31;,
  4;72,29,2,32;,
  4;79,33,2,29;,
  4;92,34,3,35;,
  4;81,26,3,34;,
  4;72,32,3,26;,
  4;80,35,3,32;,
  4;92,35,4,38;,
  4;80,36,4,35;,
  4;73,37,4,36;,
  4;84,38,4,37;,
  4;93,39,5,31;,
  4;82,40,5,39;,
  4;73,36,5,40;,
  4;80,31,5,36;,
  4;95,41,6,43;,
  4;83,42,6,41;,
  4;73,40,6,42;,
  4;82,43,6,40;,
  4;94,44,7,45;,
  4;84,37,7,44;,
  4;73,42,7,37;,
  4;83,45,7,42;,
  4;94,45,8,48;,
  4;83,46,8,45;,
  4;74,47,8,46;,
  4;87,48,8,47;,
  4;95,49,9,41;,
  4;85,50,9,49;,
  4;74,46,9,50;,
  4;83,41,9,46;,
  4;97,51,10,53;,
  4;86,52,10,51;,
  4;74,50,10,52;,
  4;85,53,10,50;,
  4;96,54,11,55;,
  4;87,47,11,54;,
  4;74,52,11,47;,
  4;86,55,11,52;,
  4;96,55,12,58;,
  4;86,56,12,55;,
  4;75,57,12,56;,
  4;89,58,12,57;,
  4;97,59,13,51;,
  4;88,60,13,59;,
  4;75,56,13,60;,
  4;86,51,13,56;,
  4;91,30,14,62;,
  4;78,61,14,30;,
  4;75,60,14,61;,
  4;88,62,14,60;,
  4;90,63,15,24;,
  4;89,57,15,63;,
  4;75,61,15,57;,
  4;78,24,15,61;,
  4;96,58,16,54;,
  4;89,64,16,58;,
  4;76,65,16,64;,
  4;87,54,16,65;,
  4;90,27,17,63;,
  4;81,66,17,27;,
  4;76,64,17,66;,
  4;89,63,17,64;,
  4;92,38,18,34;,
  4;84,67,18,38;,
  4;76,66,18,67;,
  4;81,34,18,66;,
  4;94,48,19,44;,
  4;87,65,19,48;,
  4;76,67,19,65;,
  4;84,44,19,67;,
  4;91,62,20,28;,
  4;88,68,20,62;,
  4;77,69,20,68;,
  4;79,28,20,69;,
  4;97,53,21,59;,
  4;85,70,21,53;,
  4;77,68,21,70;,
  4;88,59,21,68;,
  4;95,43,22,49;,
  4;82,71,22,43;,
  4;77,70,22,71;,
  4;85,49,22,70;,
  4;93,33,23,39;,
  4;79,69,23,33;,
  4;77,71,23,69;,
  4;82,39,23,71;;
 }
 MeshTextureCoords {
  144;
  0.000000;0.000000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.250000;0.000000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.250000;,
  0.500000;0.000000;,
  0.000000;1.000000;,
  0.250000;1.000000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;1.000000;,
  0.500000;0.750000;,
  1.000000;1.000000;,
  1.000000;0.750000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  1.000000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.000000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.250000;,
  0.000000;0.000000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.250000;0.000000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.250000;,
  0.500000;0.000000;,
  0.000000;1.000000;,
  0.250000;1.000000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;1.000000;,
  0.500000;0.750000;,
  1.000000;1.000000;,
  1.000000;0.750000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  1.000000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.000000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.250000;,
  0.000000;0.000000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.250000;0.000000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.250000;,
  0.500000;0.000000;,
  0.000000;1.000000;,
  0.250000;1.000000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;1.000000;,
  0.500000;0.750000;,
  1.000000;1.000000;,
  1.000000;0.750000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  1.000000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.000000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.250000;,
  0.000000;0.000000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.250000;0.000000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.250000;,
  0.500000;0.000000;,
  0.000000;1.000000;,
  0.250000;1.000000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;1.000000;,
  0.500000;0.750000;,
  1.000000;1.000000;,
  1.000000;0.750000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  1.000000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.000000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.250000;0.000000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.250000;,
  0.000000;1.000000;,
  0.250000;1.000000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;1.000000;,
  0.500000;0.750000;,
  1.000000;1.000000;,
  1.000000;0.750000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  1.000000;0.500000;,
  0.750000;0.500000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.250000;,
  0.000000;0.000000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.250000;0.000000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.500000;0.500000;,
  0.500000;0.250000;,
  0.500000;0.000000;,
  0.250000;1.000000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;0.750000;,
  1.000000;0.750000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  1.000000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.000000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.250000;;
 }
 MeshVertexColors {
  144;
  0;1.000000;1.000000;1.000000;1.000000;,
  1;1.000000;1.000000;1.000000;1.000000;,
  2;1.000000;1.000000;1.000000;1.000000;,
  3;1.000000;1.000000;1.000000;1.000000;,
  4;1.000000;1.000000;1.000000;1.000000;,
  5;1.000000;1.000000;1.000000;1.000000;,
  6;1.000000;1.000000;1.000000;1.000000;,
  7;1.000000;1.000000;1.000000;1.000000;,
  8;1.000000;1.000000;1.000000;1.000000;,
  9;1.000000;1.000000;1.000000;1.000000;,
  10;1.000000;1.000000;1.000000;1.000000;,
  11;1.000000;1.000000;1.000000;1.000000;,
  12;1.000000;1.000000;1.000000;1.000000;,
  13;1.000000;1.000000;1.000000;1.000000;,
  14;1.000000;1.000000;1.000000;1.000000;,
  15;1.000000;1.000000;1.000000;1.000000;,
  16;1.000000;1.000000;1.000000;1.000000;,
  17;1.000000;1.000000;1.000000;1.000000;,
  18;1.000000;1.000000;1.000000;1.000000;,
  19;1.000000;1.000000;1.000000;1.000000;,
  20;1.000000;1.000000;1.000000;1.000000;,
  21;1.000000;1.000000;1.000000;1.000000;,
  22;1.000000;1.000000;1.000000;1.000000;,
  23;1.000000;1.000000;1.000000;1.000000;,
  24;1.000000;1.000000;1.000000;1.000000;,
  25;1.000000;1.000000;1.000000;1.000000;,
  26;1.000000;1.000000;1.000000;1.000000;,
  27;1.000000;1.000000;1.000000;1.000000;,
  28;1.000000;1.000000;1.000000;1.000000;,
  29;1.000000;1.000000;1.000000;1.000000;,
  30;1.000000;1.000000;1.000000;1.000000;,
  31;1.000000;1.000000;1.000000;1.000000;,
  32;1.000000;1.000000;1.000000;1.000000;,
  33;1.000000;1.000000;1.000000;1.000000;,
  34;1.000000;1.000000;1.000000;1.000000;,
  35;1.000000;1.000000;1.000000;1.000000;,
  36;1.000000;1.000000;1.000000;1.000000;,
  37;1.000000;1.000000;1.000000;1.000000;,
  38;1.000000;1.000000;1.000000;1.000000;,
  39;1.000000;1.000000;1.000000;1.000000;,
  40;1.000000;1.000000;1.000000;1.000000;,
  41;1.000000;1.000000;1.000000;1.000000;,
  42;1.000000;1.000000;1.000000;1.000000;,
  43;1.000000;1.000000;1.000000;1.000000;,
  44;1.000000;1.000000;1.000000;1.000000;,
  45;1.000000;1.000000;1.000000;1.000000;,
  46;1.000000;1.000000;1.000000;1.000000;,
  47;1.000000;1.000000;1.000000;1.000000;,
  48;1.000000;1.000000;1.000000;1.000000;,
  49;1.000000;1.000000;1.000000;1.000000;,
  50;1.000000;1.000000;1.000000;1.000000;,
  51;1.000000;1.000000;1.000000;1.000000;,
  52;1.000000;1.000000;1.000000;1.000000;,
  53;1.000000;1.000000;1.000000;1.000000;,
  54;1.000000;1.000000;1.000000;1.000000;,
  55;1.000000;1.000000;1.000000;1.000000;,
  56;1.000000;1.000000;1.000000;1.000000;,
  57;1.000000;1.000000;1.000000;1.000000;,
  58;1.000000;1.000000;1.000000;1.000000;,
  59;1.000000;1.000000;1.000000;1.000000;,
  60;1.000000;1.000000;1.000000;1.000000;,
  61;1.000000;1.000000;1.000000;1.000000;,
  62;1.000000;1.000000;1.000000;1.000000;,
  63;1.000000;1.000000;1.000000;1.000000;,
  64;1.000000;1.000000;1.000000;1.000000;,
  65;1.000000;1.000000;1.000000;1.000000;,
  66;1.000000;1.000000;1.000000;1.000000;,
  67;1.000000;1.000000;1.000000;1.000000;,
  68;1.000000;1.000000;1.000000;1.000000;,
  69;1.000000;1.000000;1.000000;1.000000;,
  70;1.000000;1.000000;1.000000;1.000000;,
  71;1.000000;1.000000;1.000000;1.000000;,
  72;1.000000;1.000000;1.000000;1.000000;,
  73;1.000000;1.000000;1.000000;1.000000;,
  74;1.000000;1.000000;1.000000;1.000000;,
  75;1.000000;1.000000;1.000000;1.000000;,
  76;1.000000;1.000000;1.000000;1.000000;,
  77;1.000000;1.000000;1.000000;1.000000;,
  78;1.000000;1.000000;1.000000;1.000000;,
  79;1.000000;1.000000;1.000000;1.000000;,
  80;1.000000;1.000000;1.000000;1.000000;,
  81;1.000000;1.000000;1.000000;1.000000;,
  82;1.000000;1.000000;1.000000;1.000000;,
  83;1.000000;1.000000;1.000000;1.000000;,
  84;1.000000;1.000000;1.000000;1.000000;,
  85;1.000000;1.000000;1.000000;1.000000;,
  86;1.000000;1.000000;1.000000;1.000000;,
  87;1.000000;1.000000;1.000000;1.000000;,
  88;1.000000;1.000000;1.000000;1.000000;,
  89;1.000000;1.000000;1.000000;1.000000;,
  90;1.000000;1.000000;1.000000;1.000000;,
  91;1.000000;1.000000;1.000000;1.000000;,
  92;1.000000;1.000000;1.000000;1.000000;,
  93;1.000000;1.000000;1.000000;1.000000;,
  94;1.000000;1.000000;1.000000;1.000000;,
  95;1.000000;1.000000;1.000000;1.000000;,
  96;1.000000;1.000000;1.000000;1.000000;,
  97;1.000000;1.000000;1.000000;1.000000;,
  98;1.000000;1.000000;1.000000;1.000000;,
  99;1.000000;1.000000;1.000000;1.000000;,
  100;1.000000;1.000000;1.000000;1.000000;,
  101;1.000000;1.000000;1.000000;1.000000;,
  102;1.000000;1.000000;1.000000;1.000000;,
  103;1.000000;1.000000;1.000000;1.000000;,
  104;1.000000;1.000000;1.000000;1.000000;,
  105;1.000000;1.000000;1.000000;1.000000;,
  106;1.000000;1.000000;1.000000;1.000000;,
  107;1.000000;1.000000;1.000000;1.000000;,
  108;1.000000;1.000000;1.000000;1.000000;,
  109;1.000000;1.000000;1.000000;1.000000;,
  110;1.000000;1.000000;1.000000;1.000000;,
  111;1.000000;1.000000;1.000000;1.000000;,
  112;1.000000;1.000000;1.000000;1.000000;,
  113;1.000000;1.000000;1.000000;1.000000;,
  114;1.000000;1.000000;1.000000;1.000000;,
  115;1.000000;1.000000;1.000000;1.000000;,
  116;1.000000;1.000000;1.000000;1.000000;,
  117;1.000000;1.000000;1.000000;1.000000;,
  118;1.000000;1.000000;1.000000;1.000000;,
  119;1.000000;1.000000;1.000000;1.000000;,
  120;1.000000;1.000000;1.000000;1.000000;,
  121;1.000000;1.000000;1.000000;1.000000;,
  122;1.000000;1.000000;1.000000;1.000000;,
  123;1.000000;1.000000;1.000000;1.000000;,
  124;1.000000;1.000000;1.000000;1.000000;,
  125;1.000000;1.000000;1.000000;1.000000;,
  126;1.000000;1.000000;1.000000;1.000000;,
  127;1.000000;1.000000;1.000000;1.000000;,
  128;1.000000;1.000000;1.000000;1.000000;,
  129;1.000000;1.000000;1.000000;1.000000;,
  130;1.000000;1.000000;1.000000;1.000000;,
  131;1.000000;1.000000;1.000000;1.000000;,
  132;1.000000;1.000000;1.000000;1.000000;,
  133;1.000000;1.000000;1.000000;1.000000;,
  134;1.000000;1.000000;1.000000;1.000000;,
  135;1.000000;1.000000;1.000000;1.000000;,
  136;1.000000;1.000000;1.000000;1.000000;,
  137;1.000000;1.000000;1.000000;1.000000;,
  138;1.000000;1.000000;1.000000;1.000000;,
  139;1.000000;1.000000;1.000000;1.000000;,
  140;1.000000;1.000000;1.000000;1.000000;,
  141;1.000000;1.000000;1.000000;1.000000;,
  142;1.000000;1.000000;1.000000;1.000000;,
  143;1.000000;1.000000;1.000000;1.000000;;
 }
}
