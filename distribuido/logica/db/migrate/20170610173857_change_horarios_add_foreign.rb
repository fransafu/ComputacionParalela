class ChangeHorariosAddForeign < ActiveRecord::Migration[5.0]
  def change
    rename_column :horarios, :codigo_curso, :curso_id

    add_foreign_key :horarios, :cursos, column: :curso_id, primary_key: :id

  end
end
