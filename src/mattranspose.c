int matrix_transpose(int *output_matrix, int *input_matrix, int row_count, int col_count)
{
  int i,j;
  for(i = 0; i < row_count; i++){
    for(j = 0; j < col_count; j++){
      output_matrix[i * col_count + j] = input_matrix[j * row_count + i];
    }
  }
  return 0;
}