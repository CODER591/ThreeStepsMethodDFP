
void test() {
  std::vector<std::vector<int> > MATR(2, std::vector<int>(2));
  MATR[0][0]=1;
  MATR[1][0]=3;
  MATR[0][1]=2;
  MATR[1][1]=4;
  MatrOut(MATR);
  std::vector<int> v(2);
  v[0]=1;
  v[1]=2;

  //std::vector<int> res = matr_vec_multiply(MATR,v);
  std::vector<int> res = vec_mult_matr(v,MATR);
  std::cout<<"------------"<<std::endl;
  VecOut(res); //expected result is 7 10
  std::cout<<"------------"<<std::endl;
}
