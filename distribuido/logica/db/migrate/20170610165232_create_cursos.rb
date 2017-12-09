class CreateCursos < ActiveRecord::Migration[5.0]
  def change
    create_table :cursos do |t|
      t.integer :codigo
      t.integer :asignatura_id
      t.integer :semestre
      t.integer :anio
      t.integer :seccion
      t.integer :docente_id

      t.timestamps
    end
  end
end
