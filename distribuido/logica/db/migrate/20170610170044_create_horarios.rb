class CreateHorarios < ActiveRecord::Migration[5.0]
  def change
    create_table :horarios do |t|
      t.string :dia
      t.integer :codigo_curso
      t.string :curso_asignatura
      t.string :nombre_asignatura
      t.integer :periodo_id

      t.timestamps
    end
  end
end
