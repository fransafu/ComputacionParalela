class AddForeignToCursos < ActiveRecord::Migration[5.0]
  def change
    add_foreign_key :cursos, :docentes, column: :docente_id, primary_key: :id
    add_foreign_key :cursos, :asignaturas, column: :asignatura_id, primary_key: :id
  end
end
