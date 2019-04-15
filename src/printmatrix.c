void print_matrix(int* matrix, int row_count, int col_count){
  for(int i = 0; i < row_count; i++){
    for(int j = 0; j < col_count; j++){
      printf("%d ",matrix[i * col_count + j]);
    }
    printf("\n");
  }
}