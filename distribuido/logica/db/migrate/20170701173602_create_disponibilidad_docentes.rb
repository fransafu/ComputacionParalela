class CreateDisponibilidadDocentes < ActiveRecord::Migration[5.0]
  def change
    create_table :disponibilidad_docentes do |t|
      t.integer :docente_id
      t.integer :periodo_id
      t.string :dia

      t.timestamps
    end
  end
end
